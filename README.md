<div align="center"><h1>42 ft_printf</h1></div>

![ft_printf](ft_printf.png)

<div align="center"><h3>Fully buffered implementation of printf / dprintf / vprintf / vdprintf / sprintf / snprintf / vsprintf / vsnprintf</h3></div>

## SYNOPSIS

int ft_printf(const char *format, ...);<br>
int ft_dprintf(int fd, const char *format, ...);<br>
int ft_vprintf(const char *format, va_list args); <br>
int ft_vdprintf(int fd, const char *format, va_list args); <br>
int ft_sprintf(char *str, const char *format, ...); <br>
int ft_snprintf(char *str, size_t size, const char *format, ...); <br>
int ft_vsprintf(char *str, const char *format, va_list args); <br>
int ft_vsnprintf(char *str, size_t size, const char *format, va_list args);

## DESCRIPTION

The functions ft_printf() writes output to <u>stdout</u>.<br>
'd' functions write output to the given file descriptor. <br>
'v' functions are called with a <u>va_list</u> instead of a variable number of arguments. <br>
's' functions write to the character string <u>str</u>.<br>
's' functions write at most <u>size</u> bytes to <u>str</u>.<br>

### Format of the format string

The  format  string  is a character string, beginning and ending in its initial shift state, if any.  The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.  Each conversion specification is introduced by the character %, and ends with a <u>conversion specifier</u>. In between there may be (in this order) zero or more <u>flags</u>, an optional minimum <u>field width</u>, an optional <u>precision</u> and an optional <u>length modifier</u>.

The overall syntax of a conversion specification is:

<b>%[flags][width][.precision][length]specifier</b>

### Flag characters

The character % is followed by zero or more of the following flags:

| Flag | Description |
| - | - |
| # | Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. |
| 0 | Left-pads the number with zeroes (0) instead of spaces when width is specified. |
| - | 	Left-justify within the given field width. |
| (space) | If no sign is going to be written, a blank space is inserted before the value. |
| + | Forces to preceed the result with a plus or minus sign. |

### Field width

An optional decimal digit string specifying a minimum field width.  If the converted value has fewer characters than the field width, it will be padded with spaces on the left.<br>
Instead of a decimal digit string one may write "*" to specify that the field width is given in the next argument, which must be of type <u>int</u>.

### Precision

An optional precision, in the form of a period ('.')  followed by an optional decimal digit string. Instead of a decimal digit string one may write "*", to specify that the precision is given in the next argument, which must be of type <u>int</u>. If the precision is given as just '.', the precision is taken to be zero.<br>
This gives the minimum number of digits to appear for <b>d</b>, <b>i</b>, <b>u</b>, <b>o</b>, <b>x</b>, <b>X</b>, and <b>k</b> conversions, the number of digits to appear after the radix character for <b>f</b>, <b>F</b>, <b>e</b>, and <b>E</b> conversions, or the maximum number of characters to be printed from a string for <b>s</b> conversion.

### Length modifier

The length modifier modifies the length of the data type.

| Length / Specifier| d i | u o x X k | f F e E | c | s | p | n |
| - | - | - | - | - | - | - | - |
| (none) | int | unsigned int | double | int | char * | void * | int * |
| hh | signed char | unsigned char | | | | | signed char * |
| h | short int | unsigned short int | | | | | short int * |
| l | long int | unsigned long int | | wint_t | | | long int * |
| ll | long long int | unsigned long long int | | | | | long long int * |
| j | intmax_t | uintmax_t | | | | | intmax_t * |
| z | ssize_t | size_t | | | | | size_t * |
| t | ptrdiff_t | ptrdiff_t | | | | | ptrdiff_t * |
| L | | | long double |

### Conversion specifier

| Specifier | Output | Applicable flags / precision |
| - | - | - |
| d, i | Signed decimal integer | <b>- 0 (space) + .</b> |
| u | Unsigned decimal integer | <b>- 0 .</b> |
| o | Unsigned octal integer | <b>- 0 # .</b> |
| x | Unsigned hexadecimal integer (lowercase) | <b>- 0 # .</b> |
| X | Unsigned hexadecimal integer (uppercase) | <b>- 0 # .</b> |
| k | Unsigned integer in base specified as second argument<br>(This is a custom specifier. Not POSIX-compliant.) | <b>- 0 .</b> |
| f | Floating point number (lowercase) | <b>- 0 (space) # + .</b> |
| F | Floating point number (uppercase) | <b>- 0 (space) # + .</b> |
| e | Floating point number, scientific notation (lowercase) | <b>- 0 (space) # + .</b> |
| E | Floating point number, scientific notation (uppercase) | <b>- 0 (space) # + .</b> |
| c | Character | <b>-</b> | <b>-</b> |
| s | String | <b>- .</b> |
| p | Pointer address | <b>-</b> |
| % | Prints '%' character
| n | The  number  of  characters written so far is stored into the integer pointed to by the corresponding argument |

## RETURN VALUE

The number of printed characters or -1 in case of error:
- <u>format</u> parameter is NULL
- Undefined specifier
- File descriptor error
- Flag/Precision/Length not applicable
- Duplicate flag
- Write error
- Memory allocation error