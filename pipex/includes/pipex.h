/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:07:48 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/29 11:03:01 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/wait.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>

# include <stdio.h>

// === CONVERSION =============================================================

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_itoa(int nb);
int		ft_atoi(char *nptr);
long	ft_atol(char *nptr);
int		ft_antoi(char *args, size_t *i);
long	ft_antol(char *args, size_t *i);

// ============================================================================

// === COMPARAISON ============================================================

int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isvalid(const char *numbers, char *validity_str);
int		ft_isvalid_start(const char *numbers, int *start, char *validity_str);
int		ft_isdouble(long *numbers);

// ============================================================================

// === STRING =================================================================

char	**ft_split(char const *s, char c);
char	*ft_sstrjoin(int argc, char **argv);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
int		ft_strichr(char c, char *str, size_t start);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnjoin(char *s1, char *s2, size_t n);
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

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putvoids_fd(size_t ptr, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_putnbrbase_fd(size_t nb, char *base, int fd);
int		ft_put_unsigned_nbr_fd(unsigned int nb, int fd);
int		ft_putendl_fd(char *str, int fd);

// ============================================================================

// === MEMORY =================================================================

void	*ft_memchr(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

// ============================================================================

// === CHAIN LIST =============================================================

typedef struct s_list
{
	long			value;
	int				index;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(long content);
void	ft_lstadd_front(t_list **lst, t_list **new);
t_list	*ft_lstlast(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list **new);
int		ft_lstsize(t_list **lst);
void	ft_lstdelone(t_list **lst, void (*del)(long));
void	ft_lstiter(t_list **lst, void (*f)(long));
void	ft_lstclear(t_list **lst, void (*del)(long));
t_list	*ft_lstmap(t_list **lst, long (*f)(long), void (*del)(long));
int		ft_lstisdouble(t_list **numbers);
void	ft_lstshow(t_list **stack);
int		ft_lstisinf_ind(t_list **stack, long min);
int		ft_lstisinf(t_list **stack, long min);
int		ft_lstissup(t_list **stack, long min);

// ============================================================================

// === GET NEXT LINE ==========================================================

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

char	*while_no_newline(int fd, char *buffer, char *line);
char	*join_line_with_previous_line(char	*buffer, char *line);
char	*give_next_line(char *buffer);
char	*get_next_line(int fd);
char	*get_file(int fd);

// ============================================================================

// === PRINTF =================================================================

typedef unsigned int	t_unint;

int		ft_printf(const char *format, ...);

// ============================================================================

#endif
