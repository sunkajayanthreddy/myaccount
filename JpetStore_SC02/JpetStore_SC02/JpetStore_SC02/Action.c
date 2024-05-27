Action()
{
   lr_start_transaction("JpetStore_SC02_TC01_Launch");
   
	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_url("Catalog.action", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
    lr_end_transaction("JpetStore_SC02_TC01_Launch",LR_AUTO);
    
	lr_think_time(4);

	lr_start_transaction("JpetStore_SC02_TC02_Sign_In");

	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid=4F5166111421205B35945D3C28E6113A?signonForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("JpetStore_SC02_TC02_Sign_In",LR_AUTO);
	
	lr_think_time(4);

	lr_start_transaction("JpetStore_SC02_TC03_Login");

	web_submit_data("Account.action", 
		"Action=https://petstore.octoperf.com/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid=4F5166111421205B35945D3C28E6113A?signonForm=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=j2ee", ENDITEM, 
		"Name=password", "Value=j2ee", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value=QjAzS6xOE8_xELbQwEh17rSvVw8xTEBETeuhs4yBrwaK2mGwaSc8qNiyErIYC7V23_B5u4dWEIh_p1YbbHTay8PP9MVDJp1CD3prItpX_Jo=", ENDITEM, 
		"Name=__fp", "Value=h4xgQcgxC6lw4GYSB8TO8-QmaUGlCKzsJRN0lo4T-r4sp6PxZ-UNlt6k0tSQRas9", ENDITEM, 
		LAST);

	lr_end_transaction("JpetStore_SC02_TC03_Login",LR_AUTO);

	lr_think_time(4);

	lr_start_transaction("JpetStore_SC02_TC04_My_Account");

	web_url("My Account", 
		"URL=https://petstore.octoperf.com/actions/Account.action?editAccountForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("TLS_SNI", "0");

	lr_end_transaction("JpetStore_SC02_TC04_My_Account",LR_AUTO);

	lr_think_time(4);

	lr_start_transaction("JpetStore_SC02_TC05_Click_On_My_Order");

	web_reg_save_param("C_Orderid","LB=orderId=","RB=\"",LAST);
	web_reg_find("text=My Orders","savecount=click on my order",LAST);
	web_url("My Orders",
		"URL=https://petstore.octoperf.com/actions/Order.action?listOrders=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action?editAccountForm=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	if(atoi(lr_eval_string("{click on my order}"))>0)
	   {
	   	lr_output_message("valid responce");
	   	lr_end_transaction("JpetStore_SC02_TC05_Click_On_My_Order",LR_PASS);
	   }
	   else{
	   	lr_error_message("invalid responce");
	   	lr_end_transaction("JpetStore_SC02_TC05_Click_On_My_Order",LR_AUTO);
	   	lr_abort();
	   }

	web_set_sockets_option("TLS_SNI", "1");

	lr_think_time(5);
	
	lr_start_transaction("JpetStore_SC02_TC06_Click_On_Order_ID");

	web_url("1849", 
		"URL=https://petstore.octoperf.com/actions/Order.action?viewOrder=&orderId={C_Orderid}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?listOrders=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("JpetStore_SC02_TC06_Click_On_Order_ID",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("JpetStore_SC02_TC07_Sign_Out");

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?viewOrder=&orderId={C_Orderid}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
		lr_end_transaction("JpetStore_SC02_TC07_Sign_Out",LR_AUTO);

	return 0;
}