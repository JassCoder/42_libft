#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

void	test_strlen(void)
{
	printf("\n--- ft_strlen ---\n");
	printf("ft_strlen(\"Hello\") = %zu (expected 5)\n", ft_strlen("Hello"));
	printf("ft_strlen(\"\") = %zu (expected 0)\n", ft_strlen(""));
}

void	test_strdup(void)
{
	char *dup;
	
	printf("\n--- ft_strdup ---\n");
	dup = ft_strdup("Hello");
	printf("ft_strdup(\"Hello\") = %s\n", dup);
	free(dup);
	
	dup = ft_strdup("");
	printf("ft_strdup(\"\") = '%s'\n", dup);
	free(dup);
}

void	test_strlcpy(void)
{
	char dst[10];
	
	printf("\n--- ft_strlcpy ---\n");
	ft_strlcpy(dst, "Hello", 6);
	printf("dst = %s (expected Hello)\n", dst);
	
	ft_strlcpy(dst, "Hello", 3);
	printf("dst = %s (expected He)\n", dst);
}

void	test_strlcat(void)
{
	char dst[20] = "Hello";
	
	printf("\n--- ft_strlcat ---\n");
	ft_strlcat(dst, " World", 20);
	printf("dst = %s (expected Hello World)\n", dst);
}

void	test_strchr(void)
{
	printf("\n--- ft_strchr ---\n");
	printf("ft_strchr(\"Hello\", 'e') = %s (expected ello)\n", ft_strchr("Hello", 'e'));
	printf("ft_strchr(\"Hello\", 'z') = %s (expected (null))\n", ft_strchr("Hello", 'z'));
}

void	test_strrchr(void)
{
	printf("\n--- ft_strrchr ---\n");
	printf("ft_strrchr(\"Hello\", 'l') = %s (expected lo)\n", ft_strrchr("Hello", 'l'));
}

void	test_strncmp(void)
{
	printf("\n--- ft_strncmp ---\n");
	printf("ft_strncmp(\"Hello\", \"Hello\", 5) = %d (expected 0)\n", ft_strncmp("Hello", "Hello", 5));
	printf("ft_strncmp(\"Hello\", \"Hella\", 5) = %d (expected >0)\n", ft_strncmp("Hello", "Hella", 5));
	printf("ft_strncmp(\"Hello\", \"World\", 5) = %d (expected <0)\n", ft_strncmp("Hello", "World", 5));
}

void	test_strnstr(void)
{
	printf("\n--- ft_strnstr ---\n");
	printf("ft_strnstr(\"Hello World\", \"World\", 20) = %s (expected World)\n", ft_strnstr("Hello World", "World", 20));
	printf("ft_strnstr(\"Hello World\", \"World\", 5) = %s (expected (null))\n", ft_strnstr("Hello World", "World", 5));
}

void	test_atoi(void)
{
	printf("\n--- ft_atoi ---\n");
	printf("ft_atoi(\"42\") = %d (expected 42)\n", ft_atoi("42"));
	printf("ft_atoi(\"-42\") = %d (expected -42)\n", ft_atoi("-42"));
	printf("ft_atoi(\"   -42\") = %d (expected -42)\n", ft_atoi("   -42"));
	printf("ft_atoi(\"2147483647\") = %d (expected 2147483647)\n", ft_atoi("2147483647"));
	printf("ft_atoi(\"-2147483648\") = %d (expected -2147483648)\n", ft_atoi("-2147483648"));
}

void	test_calloc(void)
{
	int *arr;
	
	printf("\n--- ft_calloc ---\n");
	arr = ft_calloc(5, sizeof(int));
	if (arr)
	{
		printf("arr[0] = %d (expected 0)\n", arr[0]);
		printf("arr[4] = %d (expected 0)\n", arr[4]);
		free(arr);
	}
}

void	test_memset(void)
{
	char str[10] = "Hello";
	
	printf("\n--- ft_memset ---\n");
	ft_memset(str, 'X', 3);
	printf("str = %s (expected XXXlo)\n", str);
}

void	test_bzero(void)
{
	char str[10] = "Hello";
	
	printf("\n--- ft_bzero ---\n");
	ft_bzero(str, 3);
	printf("str[0] = %d (expected 0)\n", str[0]);
	printf("str[3] = %c (expected o)\n", str[3]);
}

void	test_memcpy(void)
{
	char src[] = "Hello";
	char dst[10];
	
	printf("\n--- ft_memcpy ---\n");
	ft_memcpy(dst, src, 5);
	dst[5] = '\0';
	printf("dst = %s (expected Hello)\n", dst);
}

void	test_memmove(void)
{
	char str[] = "HelloWorld";
	
	printf("\n--- ft_memmove ---\n");
	ft_memmove(str + 2, str, 5);
	printf("str = %s (expected HeHelloWorld?)\n", str);
}

void	test_memcmp(void)
{
	printf("\n--- ft_memcmp ---\n");
	printf("ft_memcmp(\"Hello\", \"Hello\", 5) = %d (expected 0)\n", ft_memcmp("Hello", "Hello", 5));
	printf("ft_memcmp(\"Hello\", \"Hella\", 5) = %d (expected >0)\n", ft_memcmp("Hello", "Hella", 5));
}

void	test_itoa(void)
{
	char *str;
	
	printf("\n--- ft_itoa ---\n");
	str = ft_itoa(42);
	printf("ft_itoa(42) = %s (expected 42)\n", str);
	free(str);
	
	str = ft_itoa(-42);
	printf("ft_itoa(-42) = %s (expected -42)\n", str);
	free(str);
	
	str = ft_itoa(0);
	printf("ft_itoa(0) = %s (expected 0)\n", str);
	free(str);
}

void	test_substr(void)
{
	char *sub;
	
	printf("\n--- ft_substr ---\n");
	sub = ft_substr("Hello World", 6, 5);
	printf("ft_substr(\"Hello World\", 6, 5) = %s (expected World)\n", sub);
	free(sub);
	
	sub = ft_substr("Hello", 2, 10);
	printf("ft_substr(\"Hello\", 2, 10) = %s (expected llo)\n", sub);
	free(sub);
}

void	test_strjoin(void)
{
	char *join;
	
	printf("\n--- ft_strjoin ---\n");
	join = ft_strjoin("Hello", " World");
	printf("ft_strjoin(\"Hello\", \" World\") = %s (expected Hello World)\n", join);
	free(join);
}

void	test_strtrim(void)
{
	char *trim;
	
	printf("\n--- ft_strtrim ---\n");
	trim = ft_strtrim("   Hello World   ", " ");
	printf("ft_strtrim(\"   Hello World   \", \" \") = '%s' (expected 'Hello World')\n", trim);
	free(trim);
}

void	test_split(void)
{
	char **arr;
	int i;
	
	printf("\n--- ft_split ---\n");
	arr = ft_split("Hello World 42", ' ');
	if (arr)
	{
		i = 0;
		printf("ft_split(\"Hello World 42\", ' ') = ");
		while (arr[i])
		{
			printf("\"%s\" ", arr[i]);
			free(arr[i]);
			i++;
		}
		printf("\n");
		free(arr);
	}
}

void	test_put_functions(void)
{
	printf("\n--- ft_put functions ---\n");
	printf("ft_putchar_fd('A', 1): ");
	ft_putchar_fd('A', 1);
	printf("\n");
	
	printf("ft_putstr_fd(\"Hello\", 1): ");
	ft_putstr_fd("Hello", 1);
	printf("\n");
	
	printf("ft_putendl_fd(\"Hello\", 1): ");
	ft_putendl_fd("Hello", 1);
	
	printf("ft_putnbr_fd(42, 1): ");
	ft_putnbr_fd(42, 1);
	printf("\n");
}

void	test_lst_functions(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	
	printf("\n--- ft_lst functions ---\n");
	
	list = NULL;
	node1 = ft_lstnew("First");
	node2 = ft_lstnew("Second");
	node3 = ft_lstnew("Third");
	
	ft_lstadd_front(&list, node3);
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node1);
	
	printf("ft_lstsize(list) = %d (expected 3)\n", ft_lstsize(list));
	printf("ft_lstlast(list)->content = %s (expected Third)\n", (char *)ft_lstlast(list)->content);
	
	ft_lstadd_back(&list, ft_lstnew("Fourth"));
	printf("After ft_lstadd_back: ft_lstsize(list) = %d (expected 4)\n", ft_lstsize(list));
	
	// Clean up
	// ft_lstclear(&list, free);
}

int main(void)
{
	printf("\n========== LIBFT TESTS ==========\n");
	
	test_strlen();
	test_strdup();
	test_strlcpy();
	test_strlcat();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_memcmp();
	test_itoa();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_put_functions();
	test_lst_functions();
	
	printf("\n========== ALL TESTS COMPLETE ==========\n");
	return (0);
}