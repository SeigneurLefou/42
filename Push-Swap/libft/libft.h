#ifndef LIBCONV_H
# define LIBCONV_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

// === CONVERSION =============================================================

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_itoa(int nb);
int		ft_atoi(char *nptr);
int 	ft_antoi(char *args, int *i);

// ============================================================================

// === COMPARAISON ============================================================

int	ft_isascii(int c);
int	ft_isalnum(int c);
int	ft_isdigit(int c);
int	ft_isalpha(int c);
int	ft_isprint(int c);
int ft_isvalid(const char *numbers);
int ft_isvalid_start(const char *numbers, int	*start);
int ft_isdouble(int *numbers);

// ============================================================================

// === STR ====================================================================

char	**ft_split(char const *s, char c);
char	*ft_sstrjoin(int argc, char **argv);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
int		ft_strichr(char c, char *str, size_t start);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(char *s, int c);
void	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// ============================================================================

// === PUT ====================================================================

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl_fd(char *str, int fd);

// ============================================================================

// === MEM ====================================================================

void	*ft_memchr(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

// ============================================================================


// === PUSH SWAP ==============================================================

int	*ft_parsing(int argc, char **argv);

// ============================================================================

#endif
