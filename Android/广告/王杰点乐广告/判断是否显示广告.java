Dianle.getOnlineParams("isOpen", MainActivity.this, "yes"); // 得到在线配置参数
if(!isOpen){
	//写正常功能代码
}else{
	Dianle.getTotalMoney(MainActivity.this); // 得到用户现有的积分
	if(money > 10){
		//写正常功能代码					
	}else{				
		new AlertDialog.Builder(MainActivity.this)
		.setTitle("")
		.setMessage("本软件是免费软件，但是需要下载一个应用并安装后才能使用，" +
		"里面应用都是免费的，只要下载并安装一个应用这个软件终身免费，" +
		"不出广告，获得积分超过100将有机会中话费，谢谢理解与配合。" +
		"点击'下载更多'按钮即可下载应用。您目前的积分为："+ money)
		.setPositiveButton("确定", new OnClickListener() {
								
			@Override
			public void onClick(DialogInterface dialog, int which) {
			//获得在线配置的参数，如果isOpen值是yes，就开启广告墙；如果isOpen值是no，则关闭广告墙
			Dianle.getOnlineParams("isOpen", MainActivity.this, "yes"); // 得到在线配置参数
			if(isOpen){
				Dianle.showOffers(); // 显示广告墙
			}else{
				Toast.makeText(MainActivity.this, "more", Toast.LENGTH_SHORT)	.show();
				}
			}
		}).show();
	}
}

