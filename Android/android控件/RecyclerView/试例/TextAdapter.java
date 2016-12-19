package com.adpat;

import android.support.v7.widget.CardView;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.date.Person;
import com.example.administrator.myapplication.R;

import java.util.List;

/**
 * Created by Administrator on 2015/10/20.
 */
public class TextAdapter extends RecyclerView.Adapter<TextAdapter.ViewHolder>  {
    private List<Person> persons;


    // Provide a reference to the views for each data item
    // Complex data items may need more than one view per item, and
    // you provide access to all the views for a data item in a view holder
    public static class ViewHolder extends RecyclerView.ViewHolder {
        // each data item is just a string in this case
        CardView cv;
        TextView personName;
        TextView personAge;
        ImageView personPhoto;
        public ViewHolder(View v) {
            super(v);
            cv = (CardView)itemView.findViewById(R.id.cv);
            personName = (TextView)itemView.findViewById(R.id.person_name);
            personAge = (TextView)itemView.findViewById(R.id.person_age);
            personPhoto = (ImageView)itemView.findViewById(R.id.person_photo);
        }
    }

    // Provide a suitable constructor (depends on the kind of dataset)
    public TextAdapter(List<Person> persons) {

        this.persons = persons;
    }

    // Create new views (invoked by the layout manager)
    @Override
    public TextAdapter.ViewHolder onCreateViewHolder(ViewGroup parent,
                                                   int viewType) {
        // create a new view
        View view = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.activity5, parent, false);
        // set the view's size, margins, paddings and layout parameters

        ViewHolder vh = new ViewHolder(view);

        return vh;
    }

    // Replace the contents of a view (invoked by the layout manager)
    @Override
    public void onBindViewHolder(final ViewHolder holder, final int position) {
        // - get element from your dataset at this position
        // - replace the contents of the view with that element
        holder.personName.setText(persons.get(position).name);
        holder.personAge.setText(persons.get(position).age);
        holder.personPhoto.setImageResource(persons.get(position).photoId);

    }

    // Return the size of your dataset (invoked by the layout manager)
    @Override
    public int getItemCount() {
        return  persons.size();
    }

}