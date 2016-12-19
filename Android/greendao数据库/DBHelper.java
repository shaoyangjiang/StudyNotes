package it.neokree.materialtabtest.util;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.example.greendao.Note;
import com.example.greendao.NoteDao;
import com.orhanobut.logger.Logger;

import java.util.List;

import de.greenrobot.dao.query.QueryBuilder;
import it.neokree.materialtabtest.date.ArticleInfo;
import it.neokree.materialtabtest.ui.BaseApplication;

/**
 * Created by shaoyangjiang on 2015/11/10.
 */
public class DBHelper {

    private Context context;
    public DBHelper(Context context) {
        this.context = context;
    }

    //添加数据
    public  void addNote(String id,String articleText, String picUrl, String openUri) {
        Note note = new Note(null,id,articleText,picUrl,openUri);
        getNoteDao().insert(note);
        Logger.d("插入数据" + note.getId() + note.getArticleText());
        Log.d("DaoExample", "Inserted new note, ID: " + note.getId());
    }

    //查询数据并且储存到articleInfos中
    public List<ArticleInfo> quertNote(List<Note> collectInfos,List<ArticleInfo> articleInfos){
        QueryBuilder qb = getNoteDao().queryBuilder();
        collectInfos = qb.list();
        Logger.d("getItem数据库长度"+qb.list().size());
        for(int i=0;i<qb.list().size();i++){
            articleInfos.add(new ArticleInfo(collectInfos.get(i).getArticleId(),collectInfos.get(i).getArticleText(),collectInfos.get(i).getPicUrl(),collectInfos.get(i).getOpenUri()));
        }

        return articleInfos;
    }

    //查询原始数据
    public List<Note> quertNoteOriginal(){
        QueryBuilder qb = getNoteDao().queryBuilder();
        return qb.list();
    }

    //删除一条数据
    public void deleteNote(long id){
        getNoteDao().deleteByKey(id);
    }

    //删除全部
    public void deleteAll(){
        getNoteDao().deleteAll();
    }

    //得到具体的dao
    private NoteDao getNoteDao() {
        // 通过 BaseApplication 类提供的 getDaoSession() 获取具体 Dao
       return ((BaseApplication) context.getApplicationContext()).getDaoSession().getNoteDao();
    }

    //得到数据库
    private SQLiteDatabase getDb() {
        // 通过 BaseApplication 类提供的 getDb() 获取具体 db
        return ((BaseApplication) context.getApplicationContext()).getDb();
    }


}
