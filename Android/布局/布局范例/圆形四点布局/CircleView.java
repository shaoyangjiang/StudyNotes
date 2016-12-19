package com.tiantian.test;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Style;
import android.graphics.Point;
import android.util.AttributeSet;
import android.view.View;

public class CircleView extends View{
	private Context context;
	private int circleX;
	private int circleY;
	private int radius;
	private Paint paint;
	
	public CircleView(Context context, int width, int height) {
		super(context);
		this.context = context;
		circleX = width / 2;
    	circleY = (int) ((height / 2) * 0.9);
    	radius = (int) ((width / 2) * 0.7);
		paint = new Paint();
	}
	public CircleView(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
	}
	public CircleView(Context context, AttributeSet attrs) {
		super(context, attrs);
	}

	@Override
	protected void onDraw(Canvas canvas) {
		paint = new Paint();
    	paint.setColor(Color.GRAY);
    	paint.setStyle(Style.STROKE);
    	paint.setStrokeWidth(5);
    	paint.setAntiAlias(true);
//    	canvas.drawCircle(160, 200, 110, paint);
    	canvas.drawCircle(circleX, circleY, radius, paint);
	}
	/**
	 * ȡ��Բ���Ϸ��ĵ�
	 * @return �������Ϸ��ĵ�Point����
	 */
	public Point getTopCirclePoint(){
//		return new Point(160, 200 - 110);
		return new Point(circleX, circleY - radius);
	}
	/**
	 * ȡ��Բ���·��ĵ�
	 * @return �������·��ĵ�Point����
	 */
	public Point getBottomCirclePoint(){
//		return new Point(160, 200 + 110);
		return new Point(circleX, circleY + radius);
	}
	/**
	 * ȡ��Բ����ߵĵ�
	 * @return ��������ߵĵ�Point����
	 */
	public Point getLeftCirclePoint(){
//		return new Point(160 - 110, 200);
		return new Point(circleX - radius, circleY);
	}
	/**
	 * ȡ��Բ���ұߵĵ�
	 * @return �������ұߵĵ�Point����
	 */
	public Point getRightCirclePoint(){
//		return new Point(160 + 110, 200);
		return new Point(circleX + radius, circleY);
	}

}





