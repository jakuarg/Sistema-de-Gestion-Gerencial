#include<stdio.h>
#include<stdlib.h>
#include"valuser.h"

int sus_user,sus_pass;

int login(userlen loguser, userlen logpass,FILE*arch_admin)
{
    auth reg;
    rewind(arch_admin);
    //fseek (arch_admin,0*sizeof(userlen),SEEK_SET);
	fread(&reg ,sizeof(auth),1,arch_admin);
	printf("\nINICIADO");
	while(!feof(arch_admin))//
	{
		printf("\n\nstrcmp(%s,%s)",loguser,reg.user);
		if(strcmp(loguser,reg.user)==0)
	    {
	        sus_user=1;
            if(strcmp(logpass,reg.password)==0)
            {
                printf("\n\nstrcmp(%s,%s)",logpass,reg.password);
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
    	}

		fread(&reg ,sizeof(auth),1,arch_admin);
	}
	return 0;
}

int searchmodule(userlen suser, userlen spass,FILE*arch_admin)
{
	auth reg;
	fread(&reg.user ,sizeof(userlen),1,arch_admin);
	while(!feof(arch_admin))
	{
		if(strcmp(reg.user,suser)==0)
		{
			return reg.mod;
		}
		fread(&reg.user ,sizeof(userlen),1,arch_admin);
	}
}
