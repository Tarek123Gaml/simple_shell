#include "shell.h"

/**
 * Sh_exit - exits the shell
 * @info: A structure maintains constant function prototype.
 * Return: (0) if info.argv[0] != "exit"
 */
int Sh_exit(info_t *info)
{
	int checkexit;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		checkexit = _erratoi(info->argv[1]);
		if (checkexit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * pro_change - changes the current directory of the process
 * @info: A structure to maintain constant function prototype.
 * Return: Always 0
 */
int pro_change(info_t *info)
{
	char **arg_array;

	arg_arr = info->argv;
	_puts("help call works. Function isn't implemented yet \n");
	if (0)
		_puts(*arg_arr); /* temp att_unused workaround */
	return (0);
}

/**
 * curnt_dir - changes the current directory of the process
 * @info: A structure maintain constant function prototype.
 * Return: Always 0
 */
int curnt_dir(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
