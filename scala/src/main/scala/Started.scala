import org.apache.log4j.{Level, Logger}
import org.apache.spark.sql.SparkSession

object Started {
  def main(args: Array[String]): Unit = {
    Logger.getLogger("org").setLevel(Level.ERROR)
    val sparkSession = SparkSession.builder().master("local[*]").appName("Start Spark Session").getOrCreate()
    //    val sc = sparkSession.sparkContext
    //
    //    val RDD = sc.parallelize(Seq((1, "Phu"), (2, "Khanh"), (3, "Thanh"), (4, "Do")))
    //    RDD.foreach(println)
    //    val dataFrame = RDD.toD
  }
}
