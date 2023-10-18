#include "shell.h"

/**
 *  * _strcmp - My funtion that compares two named strings
 *   *@s1: First string 1
 *    *@s2: Second string 2
 *     * Return: (1) if strings are the same, (0) on failure
 *     *Last line
 *      */
int _strcmp(char *s1, char *s2)
{
                unsigned int i = 0;

                        while (s1[i])
                                        {
                                                                if (s1[i] != s2[i])

    return (0);
                                                                                i++;
                                                                                        }
                                return (1);
}

/**
 *  * _strlen - This my function finds the length of the string
 *   *@str: our input string
 *    * Return: Specific length of the string
 *    *Last line
 *     */
int _strlen(char *str)
{
                if (!(*str))
                                        return (0);
                        return (_strlen(str + 1) + 1);
}
/**
 *  * _strcpy - My function that copies a string to another string
 *   *@dest: Pointer to the specific copied string
 *    *@src: Pointer to the exact string to copy from
 *     * Return: The pointer to copied string
 *     *Last line
 *      */
char *_strcpy(char *dest, char *src)
{
                char *aux = dest;

                        while (*src)
                                                *dest++ = *src++;
                                *dest = '\0';
                                        return (aux);
}

/**
 *  * _strcat - My function that concatenates two strings.
 *   *@dest: The input string
 *    *@src: Certain input string
 *     * Return: This returns the pointer to the resulting string
 *     *Last line
 *      */
char *_strcat(char *dest, char *src)
{
                char *temp = dest;

                        while (*dest)
                                                dest++;
                                *dest++ = '/';
                                        while (*src)
                                                                *dest++ = *src++;
                                                return (temp);
}
/**
 *  * _atoi - My function used to convert string to integer.
 *   *@s: Certain input string.
 *    * Return: Results integer from conversion.
 *    *Last line
 *     */
int _atoi(char *s)
{
                int sign = 1;
                        unsigned int total = 0;
                                char null_flag = 0;

                                        if (s == NULL)
                                                                return (0);
                                                while (*s)
                                                                {
                                                                                        if (*s == '-')

                            sign *= -1;

            if (*s >= '0' && *s <= '9')

                                    {

                                                                    null_flag = 1;


total = total * 10 + (*s - '0');


                }

                            else if (*s < '0' || *s > '9')

                                                    {

                                                                                    if (null_flag == 1)


                                break;


        }

                                            s++;

                                                    }
                                                        if (sign < 0)
                                                                                total = (-1 * (total));
                                                                return (total);
}
