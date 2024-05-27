Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");
     
     web_reg_save_param("C_jsessionid","lb=jsessionid=","rb=\"",LAST);
     
     web_reg_save_param("C__sourcePage","lb=sourcePage\" value=\"","rb=\"",LAST);
     
     web_reg_save_param("C___fp","lb=fp\" value=\"","rb=\"",LAST);
     
      lr_start_transaction("JpetStore_SC02_TC01_Launch");
      
     web_reg_find("Text=Sign In","savecount=Launchpage",LAST);
     
     web_url("Catalog.action",
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
     
     if(atoi(lr_eval_string("{Launchpage}"))>0)
        {
     	 lr_output_message("valid responce");
     	 lr_end_transaction("JpetStore_SC02_TC01_Launch",LR_PASS);
        }
        else
        { 
          lr_output_message("invalid responce");
          lr_end_transaction("JpetStore_SC02_TC01_Launch",LR_AUTO);
          lr_abort();
        }
     
	lr_think_time(2);

	lr_start_transaction("JpetStore_SC02_TC02_Signin");
	
    web_reg_find("Text=Need a user name and password","savecount=signin page",LAST);
    
	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid={C_jsessionid}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
    
     if(atoi(lr_eval_string("{signin page}"))>0)
        {
     	 lr_output_message("valid responce");
         lr_end_transaction("JpetStore_SC02_TC02_Signin",LR_PASS);
        }
        else
        { 
          lr_output_message("invalid responce");
          lr_end_transaction("JpetStore_SC02_TC02_Signin",LR_AUTO);
          lr_abort();
        }
	
	lr_think_time(2);

	lr_start_transaction("Jpet_Store_SC02_TC03_Login");

    web_reg_find("Text=Freshwater","savecount=login page",LAST);
    
	web_submit_data("Account.action", 
		"Action=https://petstore.octoperf.com/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid={C_jsessionid}", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={P_Username}", ENDITEM, 
		"Name=password", "Value={P_pwd}", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value={C__sourcePage}", ENDITEM, 
		"Name=__fp", "Value={C___fp}", ENDITEM, 
		LAST);
    
    if(atoi(lr_eval_string("{login page}"))>0)
        {
     	 lr_output_message("valid responce");
         lr_end_transaction("Jpet_Store_SC02_TC03_Login",LR_PASS);
        }
        else
        { 
          lr_output_message("invalid responce");
          lr_end_transaction("Jpet_Store_SC02_TC03_Login",LR_AUTO);
          lr_abort();
        }

	lr_think_time(2);

	lr_start_transaction("Jpet_Store_SC02_TC04_My_Account");
	
	web_reg_find("Text=Account Information","savecount=my account page",LAST);
	
	web_url("My Account", 
		"URL=https://petstore.octoperf.com/actions/Account.action?editAccountForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	if(atoi(lr_eval_string("{my account page}"))>0)
	{
		lr_output_message("valid");
		lr_end_transaction("Jpet_Store_SC02_TC04_My_Account",LR_PASS);
	}else
	{
		lr_output_message("invalid");
		lr_end_transaction("Jpet_Store_SC02_TC04_My_Account",LR_AUTO);
		lr_abort();
	}

	web_set_sockets_option("TLS_SNI", "0");

	lr_think_time(2);
	
	web_reg_save_param("C_Orderid","lb=orderId=","rb=\"",LAST);

	lr_start_transaction("Jpet_Store_SC02_TC05_Click_On_MyOrder");
	
	web_reg_find("Text=My Orders","savecount=orderpage",LAST);
	
	web_url("My Orders", 
		"URL=https://petstore.octoperf.com/actions/Order.action?listOrders=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action?editAccountForm=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("TLS_SNI", "1");

	lr_think_time(2);

	web_url("1849", 
		"URL=https://petstore.octoperf.com/actions/Order.action?viewOrder=&orderId={C_Orderid}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?listOrders=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	if(atoi(lr_eval_string("{orderpage}"))>0)
	{
		lr_output_message("valid");
		lr_end_transaction("Jpet_Store_SC02_TC05_Click_On_MyOrder",LR_PASS);
	}else
	{
		lr_output_message("invalid");
		lr_end_transaction("Jpet_Store_SC02_TC05_Click_On_MyOrder",LR_AUTO);
		lr_abort();
	}
	
	lr_think_time(2);

    lr_start_transaction("Jpet_Store_SC02_TC06_Sign_Out");
    
    web_reg_find("Text=Elevate you load-testing","savecount=signout page",LAST);
    
	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?viewOrder=&orderId={C_Orderid}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
    
    if(atoi(lr_eval_string("{signout page}"))>0)
	{
		lr_output_message("valid");
	    lr_end_transaction("Jpet_Store_SC02_TC06_Sign_Out",LR_PASS);
	}else
	{
		lr_output_message("invalid");
	    lr_end_transaction("Jpet_Store_SC02_TC06_Sign_Out",LR_AUTO);
		lr_abort();
	}
    

	return 0;
}