/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:07:48 by lchamard          #+#    #+#             */
/*   Updated: 2026/01/29 10:16:57 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	void			*value;
	int				index;
	struct s_list	*next;
}				t_list;

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
int		ft_issorted(t_list **stack);
int		ft_isprint(int c);
int		ft_isvalid(const char *numbers, char *validity_str);
int		ft_isvalid_start(const char *numbers, int	*start, char *validity_str);
int		ft_isdouble(long *numbers);

// ============================================================================

// === STRING =================================================================

char	**ft_split(char const *s, char c);
char	*ft_sstrjoin(int argc, char **argv);
char	*ft_strnjoin(char *s1, char *s2, size_t size);
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
void	ft_putnbr_fd(long nb, int fd);
void	ft_putnbr_endl(long nb);
void	ft_putendl_fd(char *str, int fd);

// ============================================================================

// === MEMORY =================================================================

void	*ft_memchr(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_free(void *arg);

// ============================================================================

// === CHAIN LIST =============================================================

t_list	*ft_lstnew(long content);
void	ft_lstadd_front(t_list **lst, t_list **new);
t_list	*ft_lstlast(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list **new);
int		ft_lstsize(t_list **lst);
void	ft_lstdelone(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list **lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstisdouble(t_list **numbers);
void	ft_lstshow(t_list **stack);
int		ft_lstisinf_ind(t_list **stack, long min);
int		ft_lstisinf(t_list **stack, long min);
int		ft_lstissup(t_list **stack, long min);

// ============================================================================

// === PUSH SWAP ==============================================================

size_t	ft_intslen(const int *list);
size_t	ft_longslen(const long *list);
t_list	*ft_parsing(int argc, char **argv);
int		ft_verif_parsing(t_list *tmp, t_list **result, size_t j);
char	*ft_fuse_argv(char **argv);
int		ft_invalid_input(int argc, char **argv, char *validity_str);
int		ft_count_int(char *args, char *validity_str);
t_list	*ft_split_int(char *args);
void	ft_swap(t_list **stack);
void	stair_sort(t_list **stacka, t_list **stackb);
void	ss(t_list **stacka, t_list **stackb);
void	sa(t_list **stacka);
void	sb(t_list **stackb);
void	ft_rotate(t_list **stack);
void	rr(t_list **stacka, t_list **stackb);
void	ra(t_list **stacka);
void	rb(t_list **stackb);
void	ft_reverse_rotate(t_list **stack);
void	rrr(t_list **stacka, t_list **stackb);
void	rra(t_list **stacka);
void	rrb(t_list **stackb);
void	ft_push(t_list **to_pop, t_list **to_push);
void	pa(t_list **stackb, t_list **stacka);
void	pb(t_list **stacka, t_list **stackb);
void	give_index(t_list **stacka);
int		ft_sqrt(int number);
void	insert_sort_b(t_list **stacka, t_list **stackb);
void	which_rotate(t_list *tmp, t_list **stackb, int len_stackb,
			long search_int);
int		ft_optimal_move(t_list **stack, int min_index, int max_index);

// ============================================================================

#endif
