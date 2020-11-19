#include<stdio.h>
#include<stdlib.h>
#include"valuser.h"

int sus_user,sus_pass;

int login(userlen loguser, userlen logpass,FILE*arch_admin)
{
    auth reg;
    rewind(arch_admin);
	fread(&reg.user, sizeof(userlen), 1, arch_admin);
	while(!feof(arch_admin))
	{
		if(strcmp(loguser,reg.user)==0)
	    {
	        sus_user=1;
            if(strcmp(logpass,reg.password)==0)
            {
                sus_pass=1;
            }
            else
            {
                sus_pass=0;
            }
	    }
	    else
	    {
		    sus_user=0;
	    }
	    if(sus_user==1 && sus_pass==1)
    	{
         	return 1;
    	}else return 0;
	}
}
