#ifndef RECEBE_SRC_DEFS_HPP
#define RECEBE_SRC_DEFS_HPP

#pragma once

#if defined(HAVE_INTTYPES_H)
#   include <cinttypes>

    typedef uint8_t u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;

    typedef int8_t i8;
    typedef int16_t i16;
    typedef int32_t i32;
    typedef int64_t i64;

    typedef float f32;
    typedef double f64;
#else
#   error "Header cinttypes not found. Integer types should be defined here."
#endif

#if defined(HAVE_STDDEF_H)
#   include <cstddef>
#endif

#define UNUSED(param) ((void) (param))

#define KiB(value) ((u64) (   ((u64) value) * 1024))
#define MiB(value) ((u64) (KiB((u64) value) * 1024))
#define GiB(value) ((u64) (MiB((u64) value) * 1024))
#define TiB(value) ((u64) (GiB((u64) value) * 1024))

#define internal static
#define global static

#endif // RECEBE_SRC_DEFS_HPP

