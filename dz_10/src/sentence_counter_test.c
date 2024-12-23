#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>
#include <cmocka.h>
#include "sentence_counter.h"

// Мокаем функцию read_lines
int __wrap_read_lines(const char *filename, char lines[256][256]) {
    check_expected_ptr(filename);
    assert_non_null(lines);

    const char (*test_lines)[256] = mock_ptr_type(const char (*)[256]);
    if (test_lines == NULL)
        return mock_type(int);
    
    memcpy(lines, test_lines, sizeof(char) * 256 * 256);

    return mock_type(int);
}

/*
    Тесты для функции count_words:
    1. Строка: This function used for counting words in sentences. - должно вернуть 8
    2. Строка состоящая из 255 символов - должно вернуть 1
    3. Пустая строка - должно вернуть 0
    4. Строка из цифр и не буквенных символов - должно вернуть 0
    5. Строка: ...Hello....Vlad... - должно вернуть 2
    6. Строка из одного символа - должно вернуть 1
*/

static void count_words_standart_sentence(void** state)
{
    (void)state;
    char sentense[256] = "This function used for counting words in sentences.";
    int expect = 8;
    assert_int_equal(count_words(sentense), expect);    
}

static void count_words_255_characters(void** state)
{
    (void)state;
    char sentense[256] = { 0 };
    memset(sentense, 'A', 255);
    int expect = 1;
    assert_int_equal(count_words(sentense), expect);    
}

static void count_words_empty_string(void** state)
{
    (void)state;
    char sentense[256] = { 0 };
    int expect = 0;
    assert_int_equal(count_words(sentense), expect);    
}

static void count_words_numbers_non_alphabetic_characters(void** state)
{
    (void)state;
    char sentense[256] = "01234 98765 !#$&'()*+,-./ :;<=>?@ {|}~ []^_`";
    int expect = 0;
    assert_int_equal(count_words(sentense), expect);    
}

static void count_words_with_dots(void** state)
{
    (void)state;
    char sentense[256] = "...Hello....Vlad...";
    int expect = 2;
    assert_int_equal(count_words(sentense), expect);    
}

static void count_words_one_character(void** state)
{
    (void)state;
    char sentense[256] = "V";
    int expect = 1;
    assert_int_equal(count_words(sentense), expect);    
}

/*
    Тесты для функции longest_sentence_in_file:
    1. Количество предложение больше 255 - должно вернуть -1
    2. Количество символов в одном предложении больше 255 - должно вернуть -1
    3. Ошибка чтения из файла (файл не существует) - должно вернуть -1
    4. Одинаковые предложения - должно вернуть 0
    5. Пустая строка - должно вернуть 0
    6. Одно предложение - должно вернуть 0
    7. Предложения из чисел и символов - должно вернуть 0
    8. Корректные предложения (предложение 4 - самое длинное) - должно вернуть 3
*/

const char* file = "";

static void longest_sentence_in_file_overflow_sentences(void** state)
{
    (void)state;
    expect_string(__wrap_read_lines, filename, file);
    will_return(__wrap_read_lines, NULL);
    will_return(__wrap_read_lines, 2);

    char longest_sentence[256] = { '\0' };
    int expect = -1;
    assert_int_equal(longest_sentence_in_file(file, longest_sentence), expect);    
}

static void longest_sentence_in_file_overflow_characters(void** state)
{
    (void)state;
    expect_string(__wrap_read_lines, filename, file);
    will_return(__wrap_read_lines, NULL);
    will_return(__wrap_read_lines, 3);

    char longest_sentence[256] = { '\0' };
    int expect = -1;
    assert_int_equal(longest_sentence_in_file(file, longest_sentence), expect);    
}

static void longest_sentence_in_file_error_read_not_exist(void** state)
{
    (void)state;
    expect_string(__wrap_read_lines, filename, file);
    will_return(__wrap_read_lines, NULL);
    will_return(__wrap_read_lines, 1);

    char longest_sentence[256] = { '\0' };
    int expect = -1;
    assert_int_equal(longest_sentence_in_file(file, longest_sentence), expect);    
}

static void longest_sentence_in_file_identical_sentences(void** state)
{
    (void)state;
    const char test_lines[256][256] = {
        "This four sentences are identical.",
        "This four sentences are identical.",
        "This four sentences are identical.",
        "This four sentences are identical.",
    };
    expect_string(__wrap_read_lines, filename, file);
    will_return(__wrap_read_lines, test_lines);
    will_return(__wrap_read_lines, 0);

    char longest_sentence[256] = { '\0' };
    int expect = 0;
    assert_int_equal(longest_sentence_in_file(file, longest_sentence), expect);    
}

static void longest_sentence_in_file_empty_sentence(void** state)
{
    (void)state;
    const char test_lines[256][256] = { "" };
    expect_string(__wrap_read_lines, filename, file);
    will_return(__wrap_read_lines, test_lines);
    will_return(__wrap_read_lines, 0);

    char longest_sentence[256] = { '\0' };
    int expect = 0;
    assert_int_equal(longest_sentence_in_file(file, longest_sentence), expect);    
}

static void longest_sentence_in_file_one_sentence(void** state)
{
    (void)state;
    const char test_lines[256][256] = { "Hello World." };
    expect_string(__wrap_read_lines, filename, file);
    will_return(__wrap_read_lines, test_lines);
    will_return(__wrap_read_lines, 0);

    char longest_sentence[256] = { '\0' };
    int expect = 0;
    assert_int_equal(longest_sentence_in_file(file, longest_sentence), expect);    
}

static void longest_sentence_in_file_numbers_non_alphabetic_characters(void** state)
{
    (void)state;
    const char test_lines[256][256] = {
        "01234 98765.",
        "!#$&'()*+,-./",
        ":;<=>?@",
        "{|}~",
        "[]^_`" 
    };
    expect_string(__wrap_read_lines, filename, file);
    will_return(__wrap_read_lines, test_lines);
    will_return(__wrap_read_lines, 0);

    char longest_sentence[256] = { '\0' };
    int expect = 0;
    assert_int_equal(longest_sentence_in_file(file, longest_sentence), expect);    
}

static void longest_sentence_in_file_correct_sentences(void** state)
{
    (void)state;
    const char test_lines[256][256] = {
        "Hello World.",
        "STM top, Arduino coming through.",
        "Putting together a computer.",
        "Bro, that's not cool at all.",
    };
    expect_string(__wrap_read_lines, filename, file);
    will_return(__wrap_read_lines, test_lines);
    will_return(__wrap_read_lines, 0);

    char longest_sentence[256] = { '\0' };
    int expect = 3;
    assert_int_equal(longest_sentence_in_file(file, longest_sentence), expect);    
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(count_words_standart_sentence),
        cmocka_unit_test(count_words_255_characters),
        cmocka_unit_test(count_words_empty_string),
        cmocka_unit_test(count_words_numbers_non_alphabetic_characters),
        cmocka_unit_test(count_words_with_dots),
        cmocka_unit_test(count_words_one_character),

        cmocka_unit_test(longest_sentence_in_file_overflow_sentences),
        cmocka_unit_test(longest_sentence_in_file_overflow_characters),
        cmocka_unit_test(longest_sentence_in_file_error_read_not_exist),
        cmocka_unit_test(longest_sentence_in_file_identical_sentences),
        cmocka_unit_test(longest_sentence_in_file_empty_sentence),
        cmocka_unit_test(longest_sentence_in_file_one_sentence),
        cmocka_unit_test(longest_sentence_in_file_numbers_non_alphabetic_characters),
        cmocka_unit_test(longest_sentence_in_file_correct_sentences)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}