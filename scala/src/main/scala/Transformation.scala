import org.apache.log4j.{Level, Logger}
import org.apache.spark.{SparkConf, SparkContext}

object Transformation {
  def main(args: Array[String]): Unit = {
    /*
    In RDD, 2 operators:
    - transformation: lazy evaluation (activated after action)
      + Narrow transformation: flatmap, map, Union, Sample, mapPartition, Filter
      + Wide transformation (shuffle transformation): use for RDD pair
        Example: groupByKey, reduceByKey, combineByKey, Distinct Intersect, join, Repartition, Coalesce
    - action
      Ex: collect, collect.sorted, foreach, take, count, top, countByValue, ...
     */
    Logger.getLogger("org").setLevel(Level.ERROR)
    val conf = new SparkConf().setMaster("local[*]").setAppName("Transformation")
    val sc = new SparkContext(conf)

    /*
      Narrow transformation
     */
    val RDD = sc.parallelize(Seq(1, 2, 3, 4, 5)) // parallelize(1 to 100)
    val RDD1 = sc.parallelize(Seq(6, 7, 8, 9, 10))
    val RDD_Union = RDD.union(RDD1)
    RDD_Union.collect().foreach(println)
    println("===========================")
    val RDD_Sample = RDD_Union.sample(false, 0.3)
    RDD_Sample.collect().sorted.foreach(println)
    println("===========================")
    val RDD_Filter = RDD_Union.filter(ele => ele % 2 == 0)
    RDD_Filter.foreach(println)
    println("===========================")

    /*
      Wide transformation
      - reduceByKey: combine pairs with each partition >< groupByKey
      - Distinct, Intersect, Join
     */
    val data = sc.textFile("src/data/input1.txt", 2)
    val data_FlatMap = data.flatMap(ele => ele.split("\\W+")).map(x => (x, 1))
    //    data_FlatMap.take(10).foreach(println)
    val wordCountGroupByKey = data_FlatMap.groupByKey().map(ele => (ele._1, ele._2.sum))
    //    wordCountGroupByKey.collect().sorted.foreach(println)
    val wordCountReduceByKey = data_FlatMap.reduceByKey((x, y) => (x + y))
    wordCountGroupByKey.collect().sorted.foreach(println)
    println("===========================")

    val RDD2 = sc.parallelize(Seq((1, 'a'), (2, 'b'), (3, 'c'), (4, 'f')))
    val RDD3 = sc.parallelize(Seq((1, 'd'), (2, 'e'), (4, 'f'), (5, 'g'), (1, 'd'), (2, 'e'), (5, 'j')))
    val RDD_Join = RDD2.join(RDD3)
    RDD_Join.foreach(println)
    println("===========================")
    val RDD_Intersect = RDD2.intersection(RDD3)
    RDD_Intersect.foreach(println)
    println("===========================")
    val RDD_Distinct = RDD3.distinct()
    RDD_Distinct.foreach(println)
    println("===========================")
  }
}
