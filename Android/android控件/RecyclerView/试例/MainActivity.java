package com.example.administrator.myapplication;


import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

import com.adpat.RecyclerItemClickListener;
import com.adpat.TextAdapter;
import com.date.Person;
import com.gc.materialdesign.widgets.ColorSelector;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity implements ColorSelector.OnColorSelectedListener {
    private RecyclerView mRecyclerView;
    private RecyclerView.Adapter mAdapter;
    private RecyclerView.LayoutManager mLayoutManager;
    public List<Person> persons;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //得到数据源
        initializeData();
        mRecyclerView = (RecyclerView) findViewById(R.id.my_recycler_view);
        // use this setting to improve performance if you know that changes
        // in content do not change the layout size of the RecyclerView
        mRecyclerView.setHasFixedSize(true);
        // use a linear layout manager
        mLayoutManager = new LinearLayoutManager(this);
        mRecyclerView.setLayoutManager(mLayoutManager);
        //把数据绑定到adapter中
        mAdapter = new TextAdapter(persons);
        //RecyclerView的监听事件
        mRecyclerView.addOnItemTouchListener(new RecyclerItemClickListener(getApplicationContext(), mRecyclerView, new RecyclerItemClickListener.OnItemClickListener() {

            @Override
            public void onItemLongClick(View view, int position) {
                Toast.makeText(getApplicationContext(), "长按" + persons.get(position).name, Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onItemClick(View view, int position) {
                Toast.makeText(getApplicationContext(), "短按"+persons.get(position).name, Toast.LENGTH_SHORT).show();
            }
        }));

        mRecyclerView.setAdapter(mAdapter);

    }

    private void initializeData(){
        persons = new ArrayList<>();
        persons.add(new Person("Emma Wilson", "23 years old", R.drawable.ic_launcher));
        persons.add(new Person("Lavery Maiss", "25 years old", R.drawable.ic_launcher));
        persons.add(new Person("Lillie Watts", "35 years old", R.drawable.ic_launcher));
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onColorSelected(int i) {

    }
}
