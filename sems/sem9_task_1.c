#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// START OF TEST DATA
typedef struct {
    char name[64];
    char codec[32];
    size_t size_bytes;
    size_t duration_sec;
    size_t width;
    size_t height;
} video_file_t;

int filter_func(const video_file_t* file)
{
    return file->size_bytes > 1000000;
}

void copy_func(video_file_t* dst, const video_file_t* src)
{
    memcpy(dst, src, sizeof(video_file_t));
}

video_file_t file1 = {
    .name = "file1.mp4",
    .codec = "H.264",
    .size_bytes = 1500000,
    .duration_sec = 120,
    .width = 1920,
    .height = 1080
};

video_file_t file2 = {
    .name = "file2.mp4",
    .codec = "VP8",
    .size_bytes = 500000,
    .duration_sec = 90,
    .width = 1280,
    .height = 720
};

video_file_t file3 = {
    .name = "file3.mp4",
    .codec = "HEVC",
    .size_bytes = 2000000,
    .duration_sec = 150,
    .width = 3840,
    .height = 2160
};

video_file_t* files[] = { &file1, &file2, &file3, '\0' };
// END OF TEST DATA

video_file_t** filter_video_files(const video_file_t** files,
    int (*filter_func)(const video_file_t*),
    void (*copy_func)(video_file_t* dst, const video_file_t* src),
    void* (*malloc_func)(size_t size))
{
    // video_file_t** filter_video_files(const video_file_t** files,
    //     filter_func_t filter_func,
    //     copy_func_t copy_func,
    //     malloc_func_t malloc_func)
    // {
    size_t len = 0;
    const video_file_t** pointer_files = files;
    while (*pointer_files) {
        if (filter_func(*pointer_files))
            len++;
        pointer_files++;
    }
    if (!len)
        return NULL;

    video_file_t** filter_files = (video_file_t**)malloc_func(sizeof(video_file_t*) * (len + 1));
    if (!filter_files)
        return NULL;

    pointer_files = files;
    size_t number = 0;
    while (*pointer_files) {
        if (filter_func(*pointer_files)) {
            filter_files[number] = (video_file_t*)malloc_func(sizeof(video_file_t));
            if (!filter_files[number]) {
                for (size_t i = 0; i < number; i++)
                    free(filter_files[i]);
                free(filter_files);
                return NULL;
            }

            copy_func(filter_files[number], *pointer_files);
            number++;
        }
        pointer_files++;
    }
    filter_files[number] = '\0';
    return filter_files;
}

int main()
{
    // Пример использования функции filter_video_files
    video_file_t** filtered_files = filter_video_files((const video_file_t**)files, filter_func, copy_func, malloc);

    // Печать отфильтрованных файлов
    if (filtered_files != NULL) {
        printf("Filtered files:\n");
        size_t i = 0;
        while (filtered_files[i]) {
            printf("Name: %s, Codec: %s, Size: %zu bytes\n",
                filtered_files[i]->name,
                filtered_files[i]->codec,
                filtered_files[i]->size_bytes);
            i++;
        }

        // Освобождение памяти
        for (size_t i = 0; filtered_files[i] != NULL; i++) {
            free(filtered_files[i]);
        }
        free(filtered_files);
    } else
        printf("No files passed the filter.\n");

    return 0;
}