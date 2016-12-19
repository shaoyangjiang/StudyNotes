package com.example.badgerdemo;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.animation.BounceInterpolator;
import android.view.animation.TranslateAnimation;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {
	private BadgeView badge8,badge4,badge6;
	private Button button1;
	private Button button2;
	private Button button3;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		//ÀÛ¼ÓÐ§¹û
		button1 = (Button) findViewById(R.id.bt1);
		badge8 = new BadgeView(this, button1);
		button1.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				if (badge8.isShown()) {
					badge8.increment(1);
				} else {
					badge8.show();
				}
			}
		});
		
        // *** custom animation ***       
		button2 = (Button) findViewById(R.id.bt2);
        badge4 = new BadgeView(this, button2);
    	badge4.setText("123");
    	badge4.setBadgePosition(BadgeView.POSITION_TOP_LEFT);
    	badge4.setBadgeMargin(15, 10);
    	badge4.setBadgeBackgroundColor(Color.parseColor("#A4C639"));
    	button2.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				TranslateAnimation anim = new TranslateAnimation(-100, 0, 0, 0);
		        anim.setInterpolator(new BounceInterpolator());
		        anim.setDuration(1000);
		    	badge4.toggle(anim, null);
			}
		});
    	
    	// *** clickable badge *** 	
    	button3 = (Button) findViewById(R.id.bt3);
    	badge6 = new BadgeView(this, button3);
    	badge6.setText("click me");
    	badge6.setBadgeBackgroundColor(Color.BLUE);
    	badge6.setTextSize(16);
    	badge6.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				Toast.makeText(MainActivity.this, "clicked badge", Toast.LENGTH_SHORT).show();
			}
		});
    	button3.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				badge6.toggle();
			}
		});
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
