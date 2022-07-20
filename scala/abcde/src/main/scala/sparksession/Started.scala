package sparksession

import org.apache.log4j.{Level, Logger}
import org.apache.spark.sql.types.{IntegerType, StringType, StructField, StructType}
import org.apache.spark.sql.{Row, SparkSession}

object Started {
  def main(args: Array[String]): Unit = {
    Logger.getLogger("org").setLevel(Level.ERROR)
    val sparkSession = SparkSession.builder().master("local[*]").appName("Start Spark Session").getOrCreate()
    val sc = sparkSession.sparkContext

    // A RDD of string
    val simpleData = Seq(Row("James ", "", "Smith", "36636", "M", 3000),
      Row("Michael ", "Rose", "", "40288", "M", 4000),
      Row("Robert ", "", "Williams", "42114", "M", 4000),
      Row("Maria ", "Anne", "Jones", "39192", "F", 4000),
      Row("Jen", "Mary", "Brown", "", "F", -1)
    )
    val rdd = sc.parallelize(simpleData)

    // your schema
    val simpleSchema = StructType(Array(
      StructField("firstname", StringType, true),
      StructField("middleName", StringType, true),
      StructField("lastname", StringType, true),
      StructField("id", StringType, true),
      StructField("gender", StringType, true),
      StructField("salary", IntegerType, true)
    ))

    // Now, let's try to create a dataframe
    val df = sparkSession.createDataFrame(rdd, simpleSchema)

    df.printSchema()
    df.show()
  }
}
