#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[64];
    char codec[32];
    size_t size_bytes;
    size_t duration_sec;
    size_t width;
    size_t height;
} video_file_t;

void* malloc_func(unsigned long long bytes) {
    return malloc(bytes);
}

void copy_func(video_file_t* dst, const video_file_t* src) {
    memcpy(dst, src, sizeof(video_file_t));
}

int is_less_func(const video_file_t* a, const video_file_t* b) {
    return a->size_bytes < b->size_bytes;
}


// video_file_t** sort_video_files(const video_file_t** files,
//     int (*is_less_func)(const video_file_t*, const video_file_t*),
//     void (*copy_func)(video_file_t*, const video_file_t*),
//     void* (*malloc_func)(unsigned long long))
// {
video_file_t** sort_video_files(const video_file_t** files,
    is_less_func_t is_less_func,
    copy_func_t copy_func,
    malloc_func_t malloc_func)
{
    size_t len = 0;
    while (files[len]) {
        len++;
    }
    if (!len)
        return NULL;

    video_file_t** sort_files = (video_file_t**)malloc_func(sizeof(video_file_t*) * (len + 1));
    if (!sort_files)
        return NULL;

    for (size_t i = 0; i < len; i++) {
        sort_files[i] = (video_file_t*)malloc_func(sizeof(video_file_t));
        if (!sort_files[i]) {
            for (size_t j = 0; j < i; j++)
                free(sort_files[j]);
            free(sort_files);
            return NULL;
        }
        copy_func(sort_files[i], files[i]);
    }

    video_file_t video_temp;

    for (size_t i = 0; i < len - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < len; j++)
            if (is_less_func(sort_files[j], sort_files[min]))
                min = j;
        
        if (min != i) {
            copy_func(&video_temp, sort_files[i]);
            copy_func(sort_files[i], sort_files[min]);
            copy_func(sort_files[min], &video_temp);
        }           
    }
    
    sort_files[len] = NULL;
    return sort_files;
}

int main(void)
{
    video_file_t file1 = {"File 1", "H264", 500, 120, 640, 512};
    video_file_t file2 = {"File 2", "H265", 1000, 150, 1920, 1080};
    video_file_t file3 = {"File 3", "VP9", 200, 90, 1280, 1024};
    video_file_t file4 = {"File 4", "MJPEG", 100, 50, 720, 480};
    video_file_t file5 = {"File 5", "VP8", 1500, 10, 4096, 2160};

    const video_file_t* files[] = {&file1, &file2, &file3, &file4, &file5, NULL};
    video_file_t** sorted_files = sort_video_files(files, is_less_func, copy_func, malloc_func);
    
    if (sorted_files) {
        for (size_t i = 0; sorted_files[i]; i++) {
            printf("File: %s, Size: %zu\n", sorted_files[i]->name, sorted_files[i]->size_bytes);
        }
        for (size_t i = 0; sorted_files[i]; i++) {
            free(sorted_files[i]);
        }
        free(sorted_files);
    } else {
        printf("Failed\n");
    }
    return 0;
}


    // SELECTIONSORT
    // in code
    // BUBBLESORT
    // for (size_t i = 0; i < len - 1; i++) {
    //     for (size_t j = 0; j < len - i - 1; j++) {
    //         if (!is_less_func(sort_files[j], sort_files[j + 1])) {
    //             copy_func(&video_temp, sort_files[j]);
    //             copy_func(sort_files[j], sort_files[j + 1]);
    //             copy_func(sort_files[j + 1], &video_temp);
    //         }
    //     }
    // }