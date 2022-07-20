import org.apache.log4j.{Level, Logger}
import org.apache.spark.{SparkConf, SparkContext}

object Linear_RDD {
  def main(args: Array[String]): Unit = {
    Logger.getLogger("org").setLevel(Level.ERROR)
    val conf = new SparkConf().setMaster("local[*]").setAppName("Linear RDD")
    val sc = new SparkContext(conf)

    val arr = sc.parallelize(1 to 10)
    println(arr.getNumPartitions)
    var arr1 = arr.map(x => x * 2)
    arr1 = arr1.map(x => x - 2)
    val arr2 = arr.intersection(arr1)
    println(arr2.toDebugString)
  }
}
