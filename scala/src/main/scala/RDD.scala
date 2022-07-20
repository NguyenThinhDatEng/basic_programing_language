import org.apache.log4j.{Level, Logger}
import org.apache.spark.{SparkConf, SparkContext}

object RDD {
  def main(args: Array[String]): Unit = {
    Logger.getLogger("org").setLevel(Level.ERROR)
    val conf = new SparkConf().setMaster("local[*]").setAppName("RDDs")
    val sc = new SparkContext(conf)

    /*
    Way 01
    RDD = sc.parallelize(Array(1, 2, 3) || Seq(1, 2, 3)) => Spark Driver
     */
    val RDD = sc.textFile("src/data/input.txt", 2)
    RDD.foreach(println)
    println(RDD.getNumPartitions)
    // number of Parts >= 2 => the data is shuffled when print on screen
    RDD.collect().foreach(println) // put 2 parts together and print

    val RDD1 = RDD.flatMap(ele => ele.split(" ")).map(x => (x, 1))
      .sortByKey(true)
      .reduceByKey(_ + _)
    RDD1.foreach(println) // a transformation
  }
}
