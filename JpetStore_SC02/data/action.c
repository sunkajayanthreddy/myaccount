Action()
{

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

	lr_think_time(54);

	lr_start_transaction("Jpet_Store_SC02_TC01_Sign_In");

	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid=4F5166111421205B35945D3C28E6113A?signonForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Jpet_Store_SC02_TC01_Sign_In",LR_AUTO);

	lr_start_transaction("Jpet_Store_SC02_TC01_Login");

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

	lr_end_transaction("Jpet_Store_SC02_TC01_Login",LR_AUTO);

	lr_think_time(47);

	lr_start_transaction("Jpet_Store_SC02_TC01_My_Account");

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

	lr_end_transaction("Jpet_Store_SC02_TC01_My_Account",LR_AUTO);

	lr_think_time(78);

	lr_start_transaction("Jpet_Store_SC02_TC01_Click_On_");

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

	lr_think_time(5);

	web_url("1849", 
		"URL=https://petstore.octoperf.com/actions/Order.action?viewOrder=&orderId=1849", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?listOrders=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Jpet_Store_SC02_TC01_Click_On_",LR_AUTO);

	lr_start_transaction("Jpet_Store_SC02_TC01_Sign_Out");

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?viewOrder=&orderId=1849", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}