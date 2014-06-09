/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:38:25 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/05 19:14:42 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define BLACK		30
# define RED		31
# define GREEN		32
# define YELLOW		33
# define BLUE		34
# define PURPLE		35
# define CYAN		36
# define WHITE		37
# define NORMAL		"0"
# define BOLD		"1"
# define REV		"7"
# define UNDERLINE	"4"
# define REVUNDER	"4;7"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcdup(const char *s, char c);
char				*ft_strndup(char *src, int i);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_open(char *name, int opt);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);
int					ft_istab(char c);
int					ft_iswhite(char c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
int					ft_putchar_fd(char c, int fd);
int					ft_putchar_col(int c, int color, char *state, int fd);
int					ft_putstr_fd(const char *s, int fd);
int					ft_putstr_col(char *str, int color, char *state, int fd);
void				ft_putendl_fd(char const *s, int fd);
int					ft_putendl_col(char *str, int color, char *state, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int nb, int base);
int					ft_sign(long n);
char				ft_newchar(long nb, int base);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcequ(char *s1, char *s2, char c);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				*ft_memalloc(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcjoin(char *s1, char *s2, char c);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(const char *s, char c);
int					ft_lstcount(t_list *list);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstswap(t_list **list, t_list *ptr, t_list *ptr2);
void				ft_tabdel(char ***tbi);
void				ft_printtab(char **tbi);
void				ft_put_log(char *str);

#endif
