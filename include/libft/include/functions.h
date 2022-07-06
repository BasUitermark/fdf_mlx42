/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 15:11:08 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/05 15:11:19 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "def.h"

//== get_next_line ==/

char	*ft_get_next_line(int fd);

//==Character Functions==//

/**
 * Checks if a character is a digit.
 * @param c The character to be checked.
 * @return Returns a 1 if true, else a 0.
 */
int		ft_isdigit(int c);

/**
 * @param c
 * @return
*/
int		ft_isspace(int c);

/**
 * Checks if a character is either a digit, a lowercase 
 * or an uppercase character.
 * @param c The character to be checked.
 * @return Returns a 1 if true, else a 0.
 */
int		ft_isalnum(int c);

/**
 * Checks if a character is either a lowercase 
 * or an uppercase character.
 * @param c The character to be checked.
 * @return Returns a 1 if true, else a 0.
 */
int		ft_isalpha(int c);

/**
 * Checks if a character is printable.
 * @param c The character to be checked.
 * @return Returns a 1 if true, else a 0.
 */
int		ft_isprint(int c);

/**
 * Checks if a character is an ASCII character.
 * @param c The character to be checked.
 * @return Returns a 1 if true, else a 0.
 */
int		ft_isascii(int c);

/**
 * @brief 
 * 
 * @param c 
 * @return int 
 */
int		ft_isupper(int c);

/**
 * @brief 
 * 
 * @param c 
 * @return int 
 */
int		ft_islower(int c);

/**
 * Changes a lowercase character to an uppercase character.
 * @param c The character to be changed.
 * @return Returns the character in uppercase.
 */
int		ft_toupper(int c);

/**
 * Changes an uppercase character to a lowercase character.
 * @param c The character to be changed.
 * @return Returns the character in lowercase.
 */
int		ft_tolower(int c);

//==String Functions ==//

/**
 * @brief 
 * 
 * @param str 
 */
void	ft_strtolower(char *str);

/**
 * @brief 
 * 
 * @param str 
 */
void	ft_strtoupper(char *str);

/**
 * Converts a string to an integer
 * @param String to be converted.
 * @return Returns an integer conversion of str.
 */
int		ft_atoi(const char *str);

/**
 * Checks the length of the string.
 * @param *str The string to be checked
 * @return Returns the length of the string
 */
size_t	ft_strlen(const char *str);

/**
 * @brief 
 * 
 * @param str 
 * @param c 
 * @return size_t 
 */
size_t	ft_strclen(char const *str, char c);

/**
 * Sets n amount of characters in s to '\0'.
 * @param *s The pointer to the address to be changed
 * @param n The amount of characters to be changed.
 */
void	ft_bzero(void *s, size_t n);

/**
 * Copies n characters from memory area src to memory area dest.
 * @param dest The destination to where the characters are copied to.
 * @param src The source where the characters are copied from.
 * @param n The amount of characters to be copied.
 */
t_size	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_strncat(char *dest, const char *src, unsigned int n);

/**
 * Concatenates the source to the destination string.
 * @param *dst The destination string
 * @param *src The source string
 * @return Returns the length of the string it tried to make.
 */
t_size	ft_strlcat(char *dst, const char *src, size_t n);

/**
 * Searches for the first occurrence of c in str.
 * If str is empty or c = '\0' it gives back a pointer
 * to the end of str.
 * @param *str The string to search through.
 * @param c The character to search for.
 * @return Returns a pointer to c in str.
 */
char	*ft_strchr(const char *str, int c);

/**
 * Searches for the last occurrence of c in str.
 * @param *str The string to search through.
 * @param c The character to search for.
 * @return Returns a pointer to c in str.
 */
char	*ft_strrchr(const char *str, int c);

/**
 * Searches for the for first occurrence of the string little in
 * string big for len number of bytes.
 * @param *big The main string to read from.
 * @param *little The string to search for.
 * @param len The amount of bytes to search through.
 */
char	*ft_strnstr(const char	*big, const char *little, t_size n);

/**
 * Compares n amount of characters of str1 with str 2.
 * @param *str1 The first string to be compared.
 * @param *str2 The second string to be compared.
 * @param n The amount of bytes to be compared.
 * @return Returns
 */
int		ft_strncmp(const char *str1, const char *str2, size_t n);

/**
 * Returns a string representation of an integer.
 * @param n The integer input.
 * @return Returns str which is a char *.
 */
char	*ft_itoa(int n);

/**
 * Returns a string representation of an unsigned integer.
 * @param n The unsigned integer input.
 * @return Returns str which is a char *.
 */
char	*ft_itoa_u(unsigned int n);

/**
 * Returns a string representation of an unsigned integer.
 * @param n The unsigned integer input.
 * @param base_set The base characters to use.
 * @return Returns str which is a char *.
 */
char	*ft_itoa_base(size_t n, char const *base_set);

/**
 * Splits a string into multiple substrings by means of a delimiter.
 * @param *s The string to be split.
 * @param c The delimiter on which point to split.
 */
char	**ft_split(char const *s, char c);

/**
 * 
 * 
*/
char	*ft_strappend(char const *s1, char const *s2);

/**
 * Duplicates a string to a new string.
 * @param *str String to be duplicated.
 * @return Returns a new string.
 */
char	*ft_strdup(const char *str);

/**
 * Copies part of a string to a new string.
 * @param *s String to take from.
 * @param start Starting point where to copy from.
 * @param len Amount of characters to copy.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * Concatenates two string to one new string.
 * @param *s1 First string to concatenate.
 * @param *s2 Second string to concatenate.
 * @return Returns a new concatenated string.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * Returns a new string with "set" removed from
 * the beginning and end of the *s.
 * @param *s1 The string to trim from
 * @param *set The set of characters to remove.
 * @return Returns a new string with set trimmed from the string.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * Applies function f to each character of s and copies it
 * to a new string
 * @param *s String to apply function f to.
 * @param *f Function to apply.
 * @return Returns a new string with f applied to it.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * Applies function f to each character of s.
 * @param *s String to apply function f to.
 * @param *f Function to apply.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

//==Memory Functions==//

/**
 * Sets a count amount of bytes * the size of the variable;
 * @param count The amount of characters
 * @param size The size of the character.
 */
void	*ft_calloc(size_t count, size_t size);

/**
 * Copies n characters from memory area src to memory area dest.
 * @param dest The destination to where the characters are copied to.
 * @param src The source where the characters are copied from.
 * @param n The amount of characters to be copied.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * Searches for the first occurrence of c in str.
 * @param *str The string to search through.
 * @param c The character to search for.
 * @param n The amount of bytes to search through.
 * @return Returns a pointer to c in str.
 */
void	*ft_memchr(const void *str, int c, size_t n);

/**
 * Sets a len amount of characters in b to character c.
 * @param *b The place in memory to set the characters.
 * @param c The character to set to.
 * @param len The mount of characters.
 */
void	*ft_memset(void *b, int c, size_t len);

/**
 * Compares n amount of bytes of str1 with str 2.
 * @param *str1 The first string to be compared.
 * @param *str2 The second string to be compared.
 * @param n The amount of bytes to be compared.
 */
int		ft_memcmp(const void *str1, const void *str2, size_t n);

/**
 * Copies len amount of bytes from src to dst. The strings may overlap.
 * @param *dst The destination of the copy.
 * @param *src The source of the copy.
 * @param len The amount of bytes to copy.
 */
void	*ft_memmove(void *dst, const void *src, size_t len);

//==Math Functions==//

/**
 * @brief 
 * 
 * @param n 
 * @return int 
 */
int		ft_abs(int n);

/**
 * @brief 
 * 
 * @param n 
 * @return int 
 */
int		ft_neg(int n);

/**
 * @brief 
 * 
 * @param n 
 * @return int 
 */
int		ft_pos(int n);

/**
 * @brief 
 * 
 * @param n 
 * @return int 
 */
int		ft_intlen(int n);

/**
 * @brief 
 * 
 * @param n 
 * @return int 
 */
int		ft_min(int *array, int size);

/**
 * @brief 
 * 
 * @param n 
 * @return int 
 */
int		ft_max(int *array, int size);

//==Filedescriptor Functions ==//

/**
 * Outputs the character ’c’ to the given file descriptor.
 * @param c The character to be outputted.
 * @param fd The filedescriptor.
 */
size_t	ft_putchar_fd(char c, int fd);

/**
 * Outputs the string *s to the given file descriptor.
 * @param *s The string to be outputted.
 * @param fd The filedescriptor.
 */
size_t	ft_putstr_fd(char *s, int fd);

/**
 * Outputs the string ’s’ to the given file descriptor, followed by a newline.
 * @param *s The string to be outputted.
 * @param fd The filedescriptor.
 */
size_t	ft_putendl_fd(char *s, int fd);

/**
 * Outputs the integer ’n’ to the given file descriptor.
 * @param n The integer to be outputted.
 * @param fd The filedescriptor.
 */
size_t	ft_putnbr_fd(int n, int fd);

/**
 * Outputs the integer base of ’n’ to the given file descriptor.
 * @param n The integer to be outputted.
 * @param fd The filedescriptor.
 * @param base The base value
 */
size_t	ft_putnbr_base_fd(size_t n, int fd, char const *base_format);

//== Linked List Functions ==//

/**
 * Creates a new element in the list.
 * The variable ’content’ is initialized with
 * the value of the parameter ’content’.
 * @param *content The content to create the list with
 * @return returns The new list entry.
 */
t_list	*ft_lstnew(void *content);

/**
 * Adds the element "new" to the beginning of the list.
 * @param **lst Pointer to the first link in the list.
 * @param *new The element to be added to the front.
 */
void	ft_lstadd_front(t_list **lst, t_list *new_item);

/**
 * Counts the number of elements in the list;
 * @param *lst The beginning of the list.
 * @return The size of "lst".
 */
int		ft_lstsize(t_list *lst);

/**
 * Returns the last element of the list.
 * @param *lst The beginning of the list.
 * @return The last element.
*/
t_list	*ft_lstlast(t_list *lst);

/**
 * Adds the element "new" to the end of the list.
 * @param **lst Pointer to the first link in the list.
 * @param *new The element to be added to the front.
 */
void	ft_lstadd_back(t_list **lst, t_list *new_item);

/**
 * Frees the given element of lst with del.
 * @param lst The element to be freed.
 * @param del The function that frees.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * Frees the entire linked list with del.
 * @param lst The list to be freed
 * @param del The function that frees.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * Iterates the function f over lst.
 * @param lst The lst to iterate over.
 * @param f The function to use with the iteration.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Iterates the function f over lst and creates a new list with 
 * the result of the iteration. If allocation fails, del frees the list.
 * @param lst The lst to iterate over.
 * @param f The function to use with the iteration.
 * @param del The function that frees.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//=== Doubly Linked List Functions ===//

t_dlist	*ft_dlstnew(void *content);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new_item);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new_item);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstfirst(t_dlist *lst);
int		ft_dlstsize(t_dlist *lst);
void	ft_dlstinsert_after(t_dlist *prev_node, t_dlist *new_item);
void	ft_dlstdel_node(t_dlist **lst, t_dlist *del_node);

//=== Print Functions ===//

int		ft_printf(const char *str, ...);
void	ft_printlist(t_list *list);
void	ft_printdlist(t_dlist *list);
void	ft_printcarray(char **str);
void	ft_printiarray(int **array, size_t lines, size_t size);
int		ft_fprintf(int fd, const char *str, ...);

#endif