#include<stdio.h>
#include<stdlib.h>
#include"valuser.h"

int sus_user,sus_pass;

int login(userlen loguser, userlen logpass,FILE *adminarch)
{
    auth reg;
    //fseek (arch_admin,0*sizeof(userlen),SEEK_SET);
    rewind(adminarch);
	fread(&reg ,sizeof(auth),1,adminarch);
	printf("\nINICIADO");
	while(feof(adminarch)==0)//
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

		fread(&reg ,sizeof(auth),1,adminarch);
	}
	return 0;
}

int searchmodule(userlen suser, userlen spass,FILE *adminarch)
{
	auth reg;
	fread(&reg.user ,sizeof(userlen),1,adminarch);
	while(!feof(adminarch))
	{
		if(strcmp(reg.user,suser)==0)
		{
			return reg.mod;
		}
		fread(&reg.user ,sizeof(userlen),1,adminarch);
	}
}
