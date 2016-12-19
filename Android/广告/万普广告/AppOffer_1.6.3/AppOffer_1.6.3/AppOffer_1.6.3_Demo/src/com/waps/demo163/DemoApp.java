package com.waps.demo163;

import java.util.List;

import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.graphics.drawable.BitmapDrawable;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import com.waps.AdInfo;
import com.waps.AdView;
import com.waps.AppConnect;
import com.waps.MiniAdView;
import com.waps.UpdatePointsNotifier;

public class DemoApp extends Activity implements View.OnClickListener, UpdatePointsNotifier {

	private TextView pointsTextView;
	private TextView SDKVersionView;

	String displayText;
	boolean update_text = false;
	String currencyName = "Points";

	final Handler mHandler = new Handler();

	LinearLayout adLinearLayout;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		AppConnect.getInstance("09f277ca386ee99cb4c910e09f562112", "WAPS", this);

		AppConnect.getInstance(this).setAdViewClassName("com.waps.demo163.MyAdView");

		// AppConnect.getInstance(this).setPushIcon(R.drawable.icon);

		// AppConnect.getInstance(this).setPushAudio(true);

		// AppConnect.getInstance(this).setCrashReport(false);

		adLinearLayout = (LinearLayout) findViewById(R.id.AdLinearLayout);
		
		Button offers = (Button) findViewById(R.id.OffersButton);
		Button owns = (Button) findViewById(R.id.OwnsButton);
		Button spendPoints = (Button) findViewById(R.id.SpendPointsButton);
		Button tabButton = (Button) findViewById(R.id.pushAdButton);
		Button feedbackBurron = (Button) findViewById(R.id.Feedback);
		Button awardBurron = (Button) findViewById(R.id.awardButton);
		Button pushInfoButton = (Button) findViewById(R.id.pushInfoButton);
		Button diyAdButton = (Button) findViewById(R.id.diyAdButton);
		Button diyAdListButton = (Button) findViewById(R.id.diyAdList);
		Button checkUpdateButton = (Button) findViewById(R.id.checkUpdateButton);

		offers.setOnClickListener(this);
		owns.setOnClickListener(this);
		spendPoints.setOnClickListener(this);
		tabButton.setOnClickListener(this);
		feedbackBurron.setOnClickListener(this);
		awardBurron.setOnClickListener(this);
		pushInfoButton.setOnClickListener(this);
		diyAdButton.setOnClickListener(this);
		diyAdListButton.setOnClickListener(this);
		checkUpdateButton.setOnClickListener(this);

		pointsTextView = (TextView) findViewById(R.id.PointsTextView);
		SDKVersionView = (TextView) findViewById(R.id.SDKVersionView);
		String sdkversion = "SDK鐗堟湰: " + AppConnect.LIBRARY_VERSION_NUMBER;
		
		String showAd = AppConnect.getInstance(DemoApp.this).getConfig("showAd");
    	if(!"".equals(showAd)){
    		sdkversion += "\n鍦ㄧ嚎鍙傛暟:showAd = "+showAd;
    		if("true".equals(showAd)){
	    		LinearLayout container = (LinearLayout) findViewById(R.id.AdLinearLayout);
	    		new AdView(this, container).DisplayAd();
    		}
		}
    	
    	SDKVersionView.setText(sdkversion);

		// AppConnect.getInstance(this).setAdBackColor(Color.argb(50, 120, 240, 120));//璁剧疆杩蜂綘骞垮憡鑳屾櫙棰滆壊
		// AppConnect.getInstance(this).setAdForeColor(Color.YELLOW);//璁剧疆杩蜂綘骞垮憡鏂囧瓧棰滆壊
		LinearLayout miniLayout = (LinearLayout) findViewById(R.id.miniAdLinearLayout);
		new MiniAdView(this, miniLayout).DisplayAd(10);// 10绉掑埛鏂颁竴娆�

		AppConnect.getInstance(this).initAdInfo();
		
		
	}

	public void onClick(View v) {
		if (v instanceof Button) {
			int id = ((Button) v).getId();

			switch (id) {
			case R.id.OffersButton:
				// 鏄剧ず鎺ㄨ崘搴旂敤鍒楄〃锛圤ffer锛�
				AppConnect.getInstance(this).showOffers(this);
				break;
			case R.id.pushAdButton:
				// 鎵嬪姩璋冪敤鎺ㄩ�骞垮憡
				AppConnect.getInstance(this).getPushAd();
				break;
			case R.id.diyAdList:
				//鑾峰彇骞垮憡鍏ㄩ儴鏁版嵁
				showList();
				break;
			case R.id.diyAdButton:
				// 鑷畾涔夊箍鍛�
				AdInfo adInfo = AppConnect.getInstance(DemoApp.this).getAdInfo();// 鑾峰彇鍗曠嫭涓�潯骞垮憡鐨勬暟鎹�
				showAdDetail(adInfo);
				break;
			case R.id.pushInfoButton:
				// 璋冪敤鎺ㄩ�娑堟伅锛屽叾涓笁椤瑰弬鏁颁负鍦ㄧ嚎閰嶇疆鎵�缃�
				String title = AppConnect.getInstance(this).getConfig("title");
				String content = AppConnect.getInstance(this).getConfig("content");
				String url = AppConnect.getInstance(this).getConfig("url");
				AppConnect.getInstance(this).pushMessage(title, content, url);
				break;
			case R.id.SpendPointsButton:
				// 娑堣垂铏氭嫙璐у竵.
				AppConnect.getInstance(this).spendPoints(10, this);
				break;
			case R.id.awardButton:
				// 濂栧姳铏氭嫙璐у竵
				AppConnect.getInstance(this).awardPoints(10, this);
				break;
			case R.id.Feedback:
				// 鐢ㄦ埛鍙嶉
				AppConnect.getInstance(this).showFeedback();
				break;
			case R.id.OwnsButton:
				// 鏄剧ず鑷搴旂敤鍒楄〃
				AppConnect.getInstance(this).showMore(this);
				break;
			case R.id.checkUpdateButton:
				// 鎵嬪姩妫�煡鏂扮増鏈�
				AppConnect.getInstance(this).checkUpdate();
				break;
			}
		}
	}

	@Override
	protected void onResume() {
		AppConnect.getInstance(this).getPoints(this);
		super.onResume();
	}

	@Override
	protected void onDestroy() {
		AppConnect.getInstance(this).finalize();
		super.onDestroy();
	}

	final Runnable mUpdateResults = new Runnable() {
		public void run() {
			if (pointsTextView != null) {
				if (update_text) {
					pointsTextView.setText(displayText);
					update_text = false;
				}
			}
		}
	};


	public void getUpdatePoints(String currencyName, int pointTotal) {
		update_text = true;
		this.currencyName = currencyName;
		displayText = currencyName + ": " + pointTotal;
		mHandler.post(mUpdateResults);
	}

	public void getUpdatePointsFailed(String error) {
		update_text = true;
		displayText = error;
		mHandler.post(mUpdateResults);
	}

	private void showList(){
		AlertDialog.Builder builder = new AlertDialog.Builder(this);
		View view = getListView();
		if(view != null){
			builder.setView(getListView());
		}else{
			builder.setMessage("广告");
		}
    	builder.create().show();
    }
    
    private View getListView(){
    	ListView listView = new ListView(this);
    	final List<AdInfo> list = AppConnect.getInstance(this).getAdInfoList();
    	if(list != null && list.size() > 0){
	    	listView.setAdapter(new MyAdapter(this, list));
	    	listView.setOnItemClickListener(new OnItemClickListener() {
				@Override
				public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
					AppConnect.getInstance(DemoApp.this).clickAd(list.get(position).getAdId());
				}
			});
	    	return listView;
    	}else{
    		return null;
    	}
    	
    }
    
    private class MyAdapter extends BaseAdapter{
    	Context context;
    	List<AdInfo> list;
    	public MyAdapter(Context context, List<AdInfo> list){
    		this.context = context;
    		this.list = list;
    	}
    	
		@Override
		public int getCount() {
			return list.size();
		}

		@Override
		public Object getItem(int position) {
			return list.get(position);
		}

		@Override
		public long getItemId(int position) {
			return position;
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			RelativeLayout r_layout;
        	ImageView app_icon;
        	TextView app_name;
        	RelativeLayout.LayoutParams rlp = new RelativeLayout.LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
        	
    		AdInfo adInfo = list.get(position);
    		r_layout = new RelativeLayout(context);
    		app_icon = new ImageView(context);
    		app_icon.setId(1);
    		app_name = new TextView(context);
    		
    		app_icon.setLayoutParams(new LayoutParams(75,75));
    		app_icon.setScaleType(ImageView.ScaleType.FIT_CENTER);
    		
    		rlp.addRule(RelativeLayout.RIGHT_OF, app_icon.getId());
    		rlp.addRule(RelativeLayout.CENTER_VERTICAL);
            app_icon.setImageDrawable(new BitmapDrawable(adInfo.getAdIcon()));  
            app_icon.setPadding(5, 5, 5, 5);
            
            app_name.setText(adInfo.getAdName());
            app_name.setTextSize(18);
            app_name.setTextColor(Color.WHITE);
            app_name.setPadding(10, 0, 0, 0);
            
            TextView content = new TextView(context);
            content.setText(adInfo.getAdText());
            content.setPadding(10, 0, 0, 0);
            
            LinearLayout layout  = new LinearLayout(context);
            layout.setOrientation(LinearLayout.VERTICAL);
            
            layout.addView(app_name);
            layout.addView(content);
            
            r_layout.addView(app_icon);
            r_layout.addView(layout, rlp);
            
        	convertView = r_layout;
        	convertView.setTag(r_layout);
            return r_layout;
		}
    }
	
	public void showAdDetail(final AdInfo adInfo){
    	try {
    		AlertDialog.Builder builder  = new AlertDialog.Builder(this);
    		if(adInfo != null){
    		
				View view = View.inflate(this, R.layout.detail, null);
				ImageView icon = (ImageView) view.findViewById(R.id.detail_icon);
				TextView title = (TextView) view.findViewById(R.id.detail_title);
				TextView version = (TextView) view.findViewById(R.id.detail_version);
				TextView filesize = (TextView) view.findViewById(R.id.detail_filesize);
				TextView points = (TextView) view.findViewById(R.id.detail_points);
				Button downButton1 = (Button) view.findViewById(R.id.detail_downButton1);
				TextView content = (TextView) view.findViewById(R.id.detail_content);
				TextView description = (TextView) view.findViewById(R.id.detail_description);
				ImageView image1 = (ImageView) view.findViewById(R.id.detail_image1);
				ImageView image2 = (ImageView) view.findViewById(R.id.detail_image2);
				
				icon.setImageBitmap(adInfo.getAdIcon());
				icon.setScaleType(ImageView.ScaleType.FIT_CENTER);
				title.setText(adInfo.getAdName());
				version.setText("  "+adInfo.getVersion());
				filesize.setText("  "+adInfo.getFilesize()+"M");
				points.setText(adInfo.getAction() +"guanggao"+String.valueOf(adInfo.getAdPoints())+currencyName);
				content.setText(adInfo.getAdText());
				description.setText(adInfo.getDescription());
				
				new GetImagesTask(adInfo, image1, image2).execute();
			
				downButton1.setOnClickListener(new OnClickListener() {
					@Override
					public void onClick(View v) {
						AppConnect.getInstance(DemoApp.this).downloadAd(adInfo.getAdId());
					}
				});
			
				builder.setView(view);
			}else{
				builder.setMessage("guanggao");
			}
    		
			builder.create().show();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
    }
	

	private class GetImagesTask extends AsyncTask<Void, Void, Boolean> {
		Bitmap bitmap1;
		Bitmap bitmap2;
		AdInfo adInfo;
		ImageView image1;
		ImageView image2;
		public GetImagesTask(AdInfo adInfo, ImageView image1, ImageView image2){
			this.adInfo = adInfo;
			this.image1 = image1;
			this.image2 = image2;
		}
		@Override
		protected Boolean doInBackground(Void... params) {
			boolean returnValue = false;
			
			try {
				bitmap1 = BitmapFactory.decodeStream(
					new DefaultHttpClient().execute(new HttpGet(adInfo.getImageUrls()[0].replaceAll(" ", "%20"))).getEntity().getContent());
				bitmap2 = BitmapFactory.decodeStream(
					new DefaultHttpClient().execute(new HttpGet(adInfo.getImageUrls()[1].replaceAll(" ", "%20"))).getEntity().getContent());
			} catch (Exception e) {
				e.printStackTrace();
			}

			return returnValue;
		}
		@Override
		protected void onPostExecute(Boolean result) {
			try {
				if (bitmap1 != null && bitmap2 != null) {
					mHandler.post(new Runnable() {
						@Override
						public void run() {
							try {
								image1.setImageBitmap(bitmap1);
								image2.setImageBitmap(bitmap2);
							} catch (Exception e) {
								e.printStackTrace();
							}
						}
					});
				}
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	
}