
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
size_t	ft_strlen1(const char *s);
char	*ft_strjoin1(char *s1, char const *s2);
char	*ft_calloc1(size_t count, size_t size);
int		ft_read(int fd, char **buff, char **rema, char **tmp);
int		ft_compar(char *s1, char *s2);

#endif
