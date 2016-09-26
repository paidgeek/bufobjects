// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_BUFFER_OBJECT_BUILDER_H
#define BUFOBJECTS_BUFFER_OBJECT_BUILDER_H

#include <cstdint>
#include <string>
#include <cstring>
#include <stdexcept>

// BUFOBJECTS_LITTLE_ENDIAN
#if !defined(BUFOBJECTS_LITTLE_ENDIAN)
#if defined(__GNUC__) || defined(__clang__)
#ifdef __BIG_ENDIAN__
#define BUFOBJECTS_LITTLE_ENDIAN 0
#else
#define BUFOBJECTS_LITTLE_ENDIAN 1
#endif
#elif defined(_MSC_VER)
#if defined(_M_PPC)
#define BUFOBJECTS_LITTLE_ENDIAN 0
#else
#define BUFOBJECTS_LITTLE_ENDIAN 1
#endif
#endif
#endif

namespace bufobjects {

  class BufferAllocator {
  public:

    BufferAllocator() {}

    virtual void *Allocate(uint32_t size) {
      void *buffer = AllocateUninitialized(size);
      if (buffer != NULL) {
        memset(buffer, 0, size);
      }
      return buffer;
    }

    virtual void *AllocateUninitialized(uint32_t size) {
      return malloc(size);
    }

    virtual void Free(void *data, uint32_t) {
      free(data);
    }

  };

  class BufferObjectBuilder {
  private:
    uint32_t capacity_;
    uint32_t max_capacity_;
    BufferAllocator allocator_;
    uint8_t *buffer_;
    uint32_t offset_;
  public:
    const uint32_t kMaxVarInt32Bytes = 5;
    const uint32_t kMaxVarInt64Bytes = 10;

    BufferObjectBuilder() : BufferObjectBuilder(1024, 8192) {}

    BufferObjectBuilder(uint32_t initial_capacity, uint32_t max_capacity) {
      allocator_ = BufferAllocator{};
      capacity_ = 0;
      offset_ = 0;
      max_capacity_ = max_capacity;
      GrowBuffer(initial_capacity);
    }

    ~BufferObjectBuilder() {
      allocator_.Free(buffer_, capacity_);
    }

    void GrowBuffer(uint32_t reserve) {
      if (capacity_ >= max_capacity_ || capacity_ + reserve - offset_ >= max_capacity_) {
        throw std::runtime_error{"Buffer overflow"};
      }

      if (capacity_ == 0) {
        buffer_ = new uint8_t[reserve];
        capacity_ = reserve;
      } else {
        uint32_t new_capacity = std::min(max_capacity_,
                                         std::max(
                                           capacity_ + reserve - GetRemaining(),
                                           capacity_ * 2));
        uint8_t *new_buffer = (uint8_t *) allocator_.Allocate(new_capacity);
        memcpy(new_buffer, buffer_, offset_);

        delete[](buffer_);
        allocator_.Free(buffer_, capacity_);

        buffer_ = new_buffer;
        capacity_ = new_capacity;
      }
    }

    inline uint32_t GetOffset() {
      return offset_;
    }

    inline uint32_t GetRemaining() {
      return capacity_ - offset_;
    }

    inline void Rewind() {
      offset_ = 0;
    }

    inline uint32_t GetCapacity() {
      return capacity_;
    }

    inline uint8_t *GetBuffer() {
      return buffer_;
    }

    inline BufferAllocator GetBufferAllocator() {
      return allocator_;
    }

    inline void SetBufferAllocator(BufferAllocator &allocator) {
      allocator_ = allocator;
    }

    inline void WriteData(void *src, uint32_t size) {
      memcpy(buffer_ + offset_, src, size);
      offset_ += size;
    }

    inline void ReadData(void *dst, uint32_t size) {
      memcpy(dst, buffer_ + offset_, size);
      offset_ += size;
    }

    inline static uint32_t GetVarInt32Size(int32_t value) {
      return GetVarUInt32Size(static_cast<uint32_t>((value << 1) ^ (value >> 31)));
    }
    inline static uint32_t GetVarUInt32Size(uint32_t value) {
      uint32_t size = 0;
      do {
        size++;
        value >>= 7;
      } while (value != 0);
      return size;
    }
    inline static uint32_t GetVarInt64Size(int64_t value) {
      return GetVarUInt64Size(static_cast<uint64_t>((value << 1) ^ (value >> 63)));
    }
    inline static uint32_t GetVarUInt64Size(uint64_t value) {
      uint32_t size = 0;
      do {
        size++;
        value >>= 7;
      } while (value != 0);

      return size;
    }
    inline static uint32_t GetStringSize(const std::string &value) {
      return static_cast<uint32_t>(value.size()) + 2;
    }

    inline void WriteBool(bool value) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      memcpy(buffer_ + offset_, &value, 1);
      offset_ += 1;
#else
      buffer_[offset_++] = static_cast<uint8_t>(value ? 1 : 0);
#endif
    }
    inline void WriteInt8(int8_t value) {
      buffer_[offset_++] = static_cast<uint8_t>(value);
    }
    inline void WriteInt16(int16_t value) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      memcpy(buffer_ + offset_, &value, 2);
      offset_ += 2;
#else
      buffer_[offset_++] = static_cast<uint8_t>(value);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 8);
#endif
    }
    inline void WriteInt32(int32_t value) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      memcpy(buffer_ + offset_, &value, 4);
      offset_ += 4;
#else
      buffer_[offset_++] = static_cast<uint8_t>(value);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 8);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 16);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 24);
#endif
    }
    inline void WriteInt64(int64_t value) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      memcpy(buffer_ + offset_, &value, 8);
      offset_ += 8;
#else
      buffer_[offset_++] = static_cast<uint8_t>(value);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 8);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 16);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 24);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 32);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 40);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 48);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 56);
#endif
    }
    inline void WriteUInt8(uint8_t value) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      memcpy(buffer_ + offset_, &value, 1);
      offset_ += 1;
#else
      buffer_[offset_++] = static_cast<uint8_t>(value);
#endif
    }
    inline void WriteUInt16(uint16_t value) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      memcpy(buffer_ + offset_, &value, 2);
      offset_ += 2;
#else
      buffer_[offset_++] = static_cast<uint8_t>(value);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 8);
#endif
    }
    inline void WriteUInt32(uint32_t value) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      memcpy(buffer_ + offset_, &value, 4);
      offset_ += 4;
#else
      buffer_[offset_++] = static_cast<uint8_t>(value);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 8);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 16);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 24);
#endif
    }
    inline void WriteUInt64(uint64_t value) {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      memcpy(buffer_ + offset_, &value, 8);
      offset_ += 8;
#else
      buffer_[offset_++] = static_cast<uint8_t>(value);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 8);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 16);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 24);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 32);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 40);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 48);
      buffer_[offset_++] = static_cast<uint8_t>(value >> 56);
#endif
    }

    inline bool ReadBool() {
      return buffer_[offset_++] == 1;
    }

    inline int8_t ReadInt8() {
      return static_cast<int8_t>(buffer_[offset_++]);
    }
    inline int16_t ReadInt16() {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      int16_t value;
      memcpy(&value, buffer_ + offset_, 2);
      offset_ += 2;
      return value;
#else
      uint8_t *buf = buffer_ + offset_;
      offset_ += 2;
      return (static_cast<int16_t>(buf[0])) |
             (static_cast<int16_t>(buf[1]) << 8);
#endif
    }
    inline int32_t ReadInt32() {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      int32_t value;
      memcpy(&value, buffer_ + offset_, 4);
      offset_ += 4;
      return value;
#else
      uint8_t *buf = buffer_ + offset_;
      offset_ += 4;
      return (static_cast<int32_t>(buf[0])) |
             (static_cast<int32_t>(buf[1]) << 8) |
             (static_cast<int32_t>(buf[2]) << 16) |
             (static_cast<int32_t>(buf[3]) << 24);
#endif
    }
    inline int64_t ReadInt64() {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      int64_t value;
      memcpy(&value, buffer_ + offset_, 8);
      offset_ += 8;
      return value;
#else
      uint8_t *buf = buffer_ + offset_;
      offset_ += 8;
      return (static_cast<int64_t>(buf[0])) |
             (static_cast<int64_t>(buf[1]) << 8) |
             (static_cast<int64_t>(buf[2]) << 16) |
             (static_cast<int64_t>(buf[3]) << 24) |
             (static_cast<int64_t>(buf[4]) << 32) |
             (static_cast<int64_t>(buf[5]) << 40) |
             (static_cast<int64_t>(buf[6]) << 48) |
             (static_cast<int64_t>(buf[7]) << 56);
#endif
    }
    inline uint8_t ReadUInt8() {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      uint8_t value;
      memcpy(&value, buffer_ + offset_, 1);
      offset_ += 1;
      return value;
#else
      return static_cast<uint8_t>(buffer_[offset_++]);
#endif
    }
    inline uint16_t ReadUInt16() {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      uint16_t value;
      memcpy(&value, buffer_ + offset_, 2);
      offset_ += 2;
      return value;
#else
      uint8_t *buf = buffer_ + offset_;
      offset_ += 2;
      return (static_cast<uint16_t>(buf[0])) |
             (static_cast<uint16_t>(buf[1]) << 8);
#endif
    }
    inline uint32_t ReadUInt32() {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      uint32_t value;
      memcpy(&value, buffer_ + offset_, 4);
      offset_ += 4;
      return value;
#else
      uint8_t *buf = buffer_ + offset_;
      offset_ += 4;
      return (static_cast<uint32_t>(buf[0])) |
             (static_cast<uint32_t>(buf[1]) << 8) |
             (static_cast<uint32_t>(buf[2]) << 16) |
             (static_cast<uint32_t>(buf[3]) << 24);
#endif
    }
    inline uint64_t ReadUInt64() {
#if defined(BUFOBJECTS_LITTLE_ENDIAN)
      uint64_t value;
      memcpy(&value, buffer_ + offset_, 8);
      offset_ += 8;
      return value;
#else
      uint8_t *buf = buffer_ + offset_;
      offset_ += 8;
      return (static_cast<uint64_t>(buf[0])) |
             (static_cast<uint64_t>(buf[1]) << 8) |
             (static_cast<uint64_t>(buf[2]) << 16) |
             (static_cast<uint64_t>(buf[3]) << 24) |
             (static_cast<uint64_t>(buf[4]) << 32) |
             (static_cast<uint64_t>(buf[5]) << 40) |
             (static_cast<uint64_t>(buf[6]) << 48) |
             (static_cast<uint64_t>(buf[7]) << 56);
#endif
    }

    inline void WriteFloat32(float value) {
      memcpy(buffer_ + offset_, &value, 4);
      offset_ += 4;
    }
    inline void WriteFloat64(double value) {
      memcpy(buffer_ + offset_, &value, 8);
      offset_ += 8;
    }

    inline float ReadFloat32() {
      float value;
      memcpy(&value, buffer_ + offset_, 4);
      offset_ += 4;
      return value;
    }
    inline double ReadFloat64() {
      double value;
      memcpy(&value, buffer_ + offset_, 8);
      offset_ += 8;
      return value;
    }

    inline uint32_t ReadVarUInt32() {
      uint32_t b;
      uint32_t value = 0;

      b = buffer_[offset_++];
      value = b & 0x7F;
      if (!(b & 0x80)) {
        return value;
      }
      b = buffer_[offset_++];
      value |= (b & 0x7F) << 7;
      if (!(b & 0x80)) {
        return value;
      }
      b = buffer_[offset_++];
      value |= (b & 0x7F) << 14;
      if (!(b & 0x80)) {
        return value;
      }
      b = buffer_[offset_++];
      value |= (b & 0x7F) << 21;
      if (!(b & 0x80)) {
        return value;
      }
      b = buffer_[offset_++];
      value |= (b & 0x7F) << 28;
      if (!(b & 0x80)) {
        return value;
      }

      for (int i = 0; i < 5; i++) {
        b = buffer_[offset_++];
        if (!(b & 0x80)) {
          break;
        }
      }

      return value;
    }

    inline void WriteVarInt32(int32_t value) {
      uint32_t uvalue = static_cast<uint32_t>((value << 1) ^ (value >> 31));
      WriteVarUInt32(uvalue);
    }

    inline void WriteVarUInt32(uint32_t value) {
      uint8_t *buf = buffer_ + offset_;

      buf[0] = static_cast<uint8_t >(value | 0x80);
      if (value >= (1 << 7)) {
        buf[1] = static_cast<uint8_t >((value >> 7) | 0x80);
        if (value >= (1 << 14)) {
          buf[2] = static_cast<uint8_t >((value >> 14) | 0x80);
          if (value >= (1 << 21)) {
            buf[3] = static_cast<uint8_t >((value >> 21) | 0x80);
            if (value >= (1 << 28)) {
              buf[4] = static_cast<uint8_t >(value >> 28);
              offset_ += 5;
            } else {
              buf[3] &= 0x7F;
              offset_ += 4;
            }
          } else {
            buf[2] &= 0x7F;
            offset_ += 3;
          }
        } else {
          buf[1] &= 0x7F;
          offset_ += 2;
        }
      } else {
        buf[0] &= 0x7F;
        offset_ += 1;
      }
    }

    inline int32_t ReadVarInt32() {
      uint32_t value = ReadVarUInt32();
      return (value >> 1) ^ -(static_cast<int32_t> (value & 1));
    }

    inline void WriteVarUInt64(uint64_t value) {
      uint32_t part0 = static_cast<uint32_t>(value);
      uint32_t part1 = static_cast<uint32_t>(value >> 28);
      uint32_t part2 = static_cast<uint32_t>(value >> 56);
      uint8_t *buf = buffer_ + offset_;

      int size;
      if (part2 == 0) {
        if (part1 == 0) {
          if (part0 < (1 << 14)) {
            if (part0 < (1 << 7)) {
              size = 1;
              goto size1;
            } else {
              size = 2;
              goto size2;
            }
          } else {
            if (part0 < (1 << 21)) {
              size = 3;
              goto size3;
            } else {
              size = 4;
              goto size4;
            }
          }
        } else {
          if (part1 < (1 << 14)) {
            if (part1 < (1 << 7)) {
              size = 5;
              goto size5;
            } else {
              size = 6;
              goto size6;
            }
          } else {
            if (part1 < (1 << 21)) {
              size = 7;
              goto size7;
            } else {
              size = 8;
              goto size8;
            }
          }
        }
      } else {
        if (part2 < (1 << 7)) {
          size = 9;
          goto size9;
        } else {
          size = 10;
          goto size10;
        }
      }

      size10:
      buf[9] = static_cast<uint8_t>((part2 >> 7) | 0x80);
      size9 :
      buf[8] = static_cast<uint8_t>((part2) | 0x80);
      size8 :
      buf[7] = static_cast<uint8_t>((part1 >> 21) | 0x80);
      size7 :
      buf[6] = static_cast<uint8_t>((part1 >> 14) | 0x80);
      size6 :
      buf[5] = static_cast<uint8_t>((part1 >> 7) | 0x80);
      size5 :
      buf[4] = static_cast<uint8_t>((part1) | 0x80);
      size4 :
      buf[3] = static_cast<uint8_t>((part0 >> 21) | 0x80);
      size3 :
      buf[2] = static_cast<uint8_t>((part0 >> 14) | 0x80);
      size2 :
      buf[1] = static_cast<uint8_t>((part0 >> 7) | 0x80);
      size1 :
      buf[0] = static_cast<uint8_t>((part0) | 0x80);

      buf[size - 1] &= 0x7F;
      offset_ += size;
    }

    inline uint64_t ReadVarUInt64() {
      uint64_t b;
      uint32_t part0 = 0, part1 = 0, part2 = 0;

      b = buffer_[offset_++];
      part0 = static_cast<uint32_t>(b & 0x7F);
      if (!(b & 0x80)) {
        goto done;
      }
      b = buffer_[offset_++];
      part0 |= static_cast<uint32_t>(b & 0x7F) << 7;
      if (!(b & 0x80)) {
        goto done;
      }
      b = buffer_[offset_++];
      part0 |= static_cast<uint32_t>(b & 0x7F) << 14;
      if (!(b & 0x80)) {
        goto done;
      }
      b = buffer_[offset_++];
      part0 |= static_cast<uint32_t>(b & 0x7F) << 21;
      if (!(b & 0x80)) {
        goto done;
      }
      b = buffer_[offset_++];
      part1 = static_cast<uint32_t>(b & 0x7F);
      if (!(b & 0x80)) {
        goto done;
      }
      b = buffer_[offset_++];
      part1 |= static_cast<uint32_t>(b & 0x7F) << 7;
      if (!(b & 0x80)) {
        goto done;
      }
      b = buffer_[offset_++];
      part1 |= static_cast<uint32_t>(b & 0x7F) << 14;
      if (!(b & 0x80)) {
        goto done;
      }
      b = buffer_[offset_++];
      part1 |= static_cast<uint32_t>(b & 0x7F) << 21;
      if (!(b & 0x80)) {
        goto done;
      }
      b = buffer_[offset_++];
      part2 = static_cast<uint32_t>(b & 0x7F);
      if (!(b & 0x80)) {
        goto done;
      }
      b = buffer_[offset_++];
      part2 |= static_cast<uint32_t>(b & 0x7F) << 7;
      if (!(b & 0x80)) {
        goto done;
      }

      done:
      return part0 | (static_cast<uint64_t>(part1) << 28) | (static_cast<uint64_t>(part2) << 56);
    }

    inline void WriteVarInt64(int64_t value) {
      uint64_t uvalue = static_cast<uint64_t>((value << 1) ^ (value >> 63));
      WriteVarUInt64(uvalue);
    }

    inline int64_t ReadVarInt64() {
      uint64_t result = ReadVarUInt64();
      return (result >> 1) ^ -(static_cast<int64_t> (result & 1));
    }

    inline void WriteString(const std::string &value) {
      uint32_t len = static_cast<uint32_t>(value.length());
      WriteVarUInt32(len);
      memcpy(&buffer_[offset_], value.data(), len);
      offset_ += len;
    }
    inline std::string ReadString() {
      uint32_t len = ReadVarUInt32();
      char *data = (char *) allocator_.AllocateUninitialized(len + 1);
      data[len] = '\0';

      memcpy(data, &buffer_[offset_], len);
      offset_ += len;

      std::string str = std::string{data};
      allocator_.Free(data, len + 1);

      return str;
    }

  };

}

#endif
