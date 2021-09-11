/*
** EPITECH PROJECT, 2020
** bitmap_header.c
** File description:
** bitmap_header
*/

#include "bitmap.h"
#include <sys/types.h>
#include <stddef.h>

void make_bmp_header(bmp_header_t *header, size_t size)
{
    int global_size = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
    header->magic = 0x4D42;
    header->size = global_size + (size * size * 4);
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = global_size;
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->size = sizeof(bmp_info_header_t);
    header->width = size;
    header->heigth = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * size * 4;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}