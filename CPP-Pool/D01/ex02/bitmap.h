/*
** EPITECH PROJECT, 2020
** bitmap.h
** File description:
** bitmap include
*/

#ifndef BITMAP_H
#define BITMAP_H

#include <stddef.h>
#include <stdint.h>

typedef struct __attribute__ ((packed)) s_bmp_header
{
    int16_t magic;
    int32_t size;
    int16_t _app1;
    int16_t _app2;
    int32_t offset;

} bmp_header_t;

typedef struct __attribute__ ((packed)) s_bmp_info_header
{
    int32_t size;
    uint32_t width;
    uint32_t heigth;
    int16_t planes;
    int16_t bpp;
    int32_t compression;
    int32_t raw_data_size;
    uint32_t h_resolution;
    uint32_t v_resolution;
    int32_t palette_size;
    int32_t important_colors;
} bmp_info_header_t;


void make_bmp_header(bmp_header_t *header, size_t size);
void make_bmp_info_header(bmp_info_header_t *header, size_t size);

#endif