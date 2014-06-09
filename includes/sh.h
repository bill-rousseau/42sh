/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 18:02:31 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/08 18:02:33 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

/*
**						GRAMMAR USED FOR SH
**	S			==	[Exp]+
**	Exp			==	andexp
**	andexp		==	sepexp [[&&] andexp]?
**	sepexp		==	orexp [[;] sepexp]?
**	orexp		==	right_rexp [[||] orexp]?
**	right_rexp	==	pipeexp [[> | >>] file]?
**	pipeexp		==	left_rexp [[|] pipeexp]?
**	left_rexp	==	[[<] file] ]? command [[<] file] ]?
**	command		==	word
**	file		==	word
*/

# define PARS_AND_NOCMD "Near &&, command needed."
# define PARS_OR_NOCMD "Near ||, command needed."
# define PARS_RIGHT_NOCMD "Near > or >>, command needed."
# define PARS_RIGHT_NOFILE "Near > or >>, file needed."
# define PARS_PIPE_NOCMD "Near |, command needed."
# define PARS_LEFT_USAGE "<: usage: \"< file command\" or \"command < file\"."

# define K0					key[0]
# define K1					key[1]
# define K2					key[2]
# define K3					key[3]
# define RIGHTS				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

enum					e_status
{
	_wait, _and, _sep, _or, _right, _pipe, _left, _word, _end
};

enum					e_lex_error
{
	_err_lex
};

typedef int				(*t_builtin_fct)(char **);

typedef struct			s_env
{
	char				*name;
	char				*value;
	struct s_env		*next;
	struct s_env		*prev;
}						t_env;

typedef struct			s_char
{
	char				c;
	struct s_char		*next;
	struct s_char		*prev;
}						t_char;

typedef struct			s_cursor
{
	int					pos_col;
	t_char				*start;
	t_char				*current;
	t_char				*end;
}						t_cursor;

typedef struct			s_fork
{
	int					pid;
	struct s_fork		*next;
}						t_fork;

typedef struct			s_cmd
{
	char				**args;
	int					type;
	struct s_cmd		*next;
}						t_cmd;

typedef struct			s_lex
{
	int					type;
	char				*str;
	struct s_lex		*next;
	struct s_lex		*prev;
}						t_lex;

typedef struct			s_auto
{
	int					status;
	int					i;
	char				*buf;
	t_lex				*l_lex;
}						t_auto;

typedef int				(*t_func)(t_auto *, char);

typedef struct			s_tree
{
	int					type;
	t_lex				*list;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;

extern t_env			*g_env;
extern struct winsize	g_winsize;
extern struct termios	*g_backup_term;
extern t_fork			*g_fork;
extern unsigned int		g_last_return;

/*
** sh_env_tools.c
*/

t_env					*sh_init_env(char **envp);
t_env					*sh_get_env_var(char *str);
char					**sh_getenv(void);
void					sh_printenv(t_env *env);
void					sh_up_shlvl(t_env *env);

/*
** sh_tools.c
*/

void					*sh_malloc(unsigned int size);
int						sh_putchar(int c);
char					**sh_tree_to_tab(t_lex *data);

/*
** sh_error.c
*/

void					sh_error_exit(int num, char *str);
int						sh_error(int error, char *str);
int						sh_error_str(int error, char *str);

/*
** sh_winsize.c
*/

void					sh_init_winsize(struct winsize *win);

/*
** sh_signal.c
*/

void					sh_signal(void);

/*
** sh_prompt.c
*/

int						sh_prompt(char **line);
void					sh_prompt_pwd(void);
int						sh_prompt_user(void);
int						sh_prompt_host(void);

/*
** sh_term.c
*/

int						sh_init_term(void);
void					sh_exit_term(void);

/*
** sh_get_line.c
*/

char					*sh_get_line(int len);
char					*sh_convert(t_cursor *cursor);
void					sh_del_lstchar(t_cursor *cursor);

/*
** sh_cursor.c
*/

t_cursor				*sh_init_cursor(int len);
t_char					*sh_newchar(char c);
void					sh_insert_char(t_cursor *cursor, char c);

/*
** sh_term_tools.c
*/

void					sh_printlst(t_cursor *cursor);

/*
** sh_execkey.c
*/

void					sh_execkey(char	*key, t_cursor *cursor);
void					sh_backspace(t_cursor *cursor);
void					sh_delete(t_cursor *cursor);
void					sh_eof(void);

/*
** sh_movecursor.c
*/

void					sh_movecursor(t_cursor *cursor, char *key);

/*
** sh_exit.c
*/

int						sh_exitshell(char **agrs);

/*
** sh_analyze.c
*/

t_tree					*sh_analyze(char *line);
t_tree					*sh_pars(t_lex *lex);

/*
** sh_automaton.c
*/

int						sh_initauto(t_auto *autom, int size);
int						sh_automaton(t_auto *autom, char c);
int						sh_addtoken(t_auto *autom);

/*
** sh_lst_lex.c
*/

void					sh_dellex(t_lex **l_lex);
int						sh_lexlen(t_lex *lst);
t_lex					*sh_newlex(t_auto *autom);
void					sh_lexadd(t_lex **list, t_lex *elem);

/*
** sh_lex_and.c
*/

int						sh_lex_and(t_auto *autom, char c);
int						sh_lex_wait(t_auto *autom, char c);
int						sh_lex_sep(t_auto *autom, char c);
int						sh_lex_or(t_auto *autom, char c);
int						sh_lex_right(t_auto *autom, char c);

/*
** sh_lex_left.c
*/

int						sh_lex_left(t_auto *autom, char c);
int						sh_lex_word(t_auto *autom, char c);
int						sh_lex_pipe(t_auto *autom, char c);

/*
** sh_tree.c
*/

t_tree					*sh_newtree(t_lex *l_lex);
void					sh_deltree(t_tree **tree);
int						sh_addtree(t_tree *tree, t_lex *tmp, int type);

/*
** 	sh_pars_and.c
*/

int						sh_pars_and(t_tree *tree);
int						sh_pars_sep(t_tree *tree);
int						sh_pars_or(t_tree *tree);
int						sh_pars_right(t_tree *tree);
int						sh_pars_pipe(t_tree *tree);

/*
** sh_pars_left.c
*/

int						sh_pars_left(t_tree *tree);
int						sh_pars_cmd(t_tree *tree);
int						sh_pars_left_first(t_tree *tree, t_lex *tmp);
int						sh_pars_left_mid(t_tree *tree, t_lex *tmp);

/*
** sh_exec_tree.c
*/

void					sh_exec_tree(t_tree *tree);

/*
** sh_exec_pipe.c
*/

void					sh_exec_pipe(t_tree *tree);
void					sh_pipe_child(t_tree *tree, int pipefd[2]);
void					sh_pipe_father(t_tree *tree, int pipefd[2]);

/*
** sh_exec_and.c
*/

void					sh_exec_and(t_tree *tree);
void					sh_exec_or(t_tree *tree);

/*
** sh_exec_left.c
*/

void					sh_exec_left(t_tree *tree);
int						sh_open(char *file);

/*
** sh_exec_right.c
*/

void					sh_exec_right(t_tree *tree);
int						sh_get_fd(t_tree *tree);
int						sh_open2(char *file, char *type);

/*
** sh_exec_word.c
*/

void					sh_exec_word(t_tree *tree);
int						sh_is_builtin(char *name);
int						sh_exec_builtins(char **args, int i);

/*
** sh_exec_cmd.c
*/

void					sh_exec_cmd(char **args, char *path);
int						sh_testaccess(char *bin);
char					*sh_get_bin(char *args, char *path_env);

/*
** sh_fork.c
*/

int						sh_fork(void);
int						sh_unset_fork(int pid);

/*
** sh_wait.c
*/

void					sh_wait(int pid);

/*
** sh_cd.c
*/

int						sh_cd(char **args);
void					sh_update_cd(void);

/*
** sh_env.c
*/

int						sh_env(char **args);
void					sh_modif_env(char **args, int *i, char *path);

/*
** sh_setenv.c
*/

int						sh_setenv(char **args);
void					sh_exec_setenv(char *name, char *value);

/*
** sh_echo.c
*/

int						sh_echo(char **args);

/*
** sh_jobs.c
*/

int						sh_jobs(char **args);

/*
** sh_unsetenv.c
*/

int						sh_unsetenv(char **args);
void					sh_exec_unsetenv(char *name);

#endif
