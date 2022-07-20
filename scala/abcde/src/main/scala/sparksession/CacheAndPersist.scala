package sparksession

import org.apache.log4j.{Level, Logger}
import org.apache.spark.sql.{Row, SparkSession}
import org.apache.spark.sql.types.{IntegerType, StringType, StructField, StructType}
import org.apache.spark.storage.StorageLevel

// Optimize computing performance
// favorable for parallel computation

object CacheAndPersist {
  def main(args: Array[String]): Unit = {
    Logger.getLogger("org").setLevel(Level.ERROR)
    val spark = SparkSession.builder().master("local[*]").appName("Cache and Persist").getOrCreate()
    val sc = spark.sparkContext

    // A RDD of rows
    val simpleData = Seq(Row("James ", "", "Smith", "36636", 3000),
      Row("Michael ", "Rose", "", "40288", 4000),
      Row("Robert ", "", "Williams", "42114", 4000),
      Row("Maria ", "Anne", "Jones", "39192", 4000),
      Row("Jen", "Mary", "Brown", "", -1)
    )
    val rdd = sc.parallelize(simpleData)

    // your schema
    val simpleSchema = StructType(Array(
      StructField("firstname", StringType, true),
      StructField("middleName", StringType, true),
      StructField("lastname", StringType, true),
      StructField("id", StringType, true),
      StructField("salary", IntegerType, true)
    ))

    // Now, let's try to create a dataframe
    val df = spark.createDataFrame(rdd, simpleSchema)

    val df_cache = df.cache() // store on RAM
    // df.unpersist(true)
    val df_persist = df.persist(StorageLevel.MEMORY_AND_DISK) // store on RAM, DISK, or RAM and DISK
    df_persist.show()
  }
}
