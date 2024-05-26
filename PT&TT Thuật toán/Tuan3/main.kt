import android.content.DialogInterface
import android.content.Intent
import androidx.appcompat.app.AlertDialog
import androidx.appcompat.app.AppCompatActivity

class UpdateNewsActivity : AppCompatActivity() {

    // Khai báo biến newsEntity và newsDB ở đây

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_update_news)

        val btnDelete: Button = findViewById(R.id.btnDelete)
        btnDelete.setOnClickListener {
            showDeleteConfirmationDialog()
        }
    }

    private fun showDeleteConfirmationDialog() {
        val builder = AlertDialog.Builder(this)
        builder.setMessage("Bạn có chắc chắn muốn xóa?")
            .setPositiveButton("Có") { dialog, which ->
                // Xóa dữ liệu khi người dùng chọn "Có"
                deleteNews()
            }
            .setNegativeButton("Không") { dialog, which ->
                // Không làm gì nếu người dùng chọn "Không"
            }
            .show()
    }

    private fun deleteNews() {
        val newsEntity = NewsEntity(newsId, defaultTitle, defaultDesc)
        newsDB.doa().deleteNews(newsEntity)

        // Chuyển đến MainActivity
        startActivity(Intent(this@UpdateNewsActivity, MainActivity::class.java))
        finish()
    }
}
