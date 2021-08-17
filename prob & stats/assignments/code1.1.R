###1.1
data = matrix(c(47, 53, 16, 189, 746, 228, 807, 1387, 438, 1768, 946, 115), ncol = 4, nrow = 3)
colnames(data) = c("T1", "T2", "T3", "T4")
rownames(data) = c("A", "B", "C")
chisq.test(data)

###1.2
#generating data to matrix
data = matrix(c(11,15,3,41,5,3,22,30,5,7,3,15), ncol = 3, nrow = 4)
colnames(data) = c("Us", "Japan", "UK")
rownames(data) = c("Colorectal", "Breast", "Stomach", "Other")

#printing the matrix
print(data)

#chi-squared test
result <- chisq.test(data)

#printing result
print(result)

###1.3
library(readxl)
data <- read_excel("C:/Users/xps/Desktop/data.xlsx")
View(data)
data$store = as.factor(data$store)
aov = aov(data=data, formula = sales~store)
summary(aov)


###1.4
Industries <- gl(3,16,48, labels=c("Refrigeration","Construction Materials","Computer Services"))
Districts <- gl(4,4,48, labels=c("1","2","3","4"))
Sales <- c(2.5,2.7,2,3, 13.1,3.5,2.7,0, 2,2.4,0,0, 5,5.4,0,0, 0.6,10.4,0,0, 15,0,0,0, 9.5,9.3,9.1,0, 19.5,17.5,0,0, 1.2,1,9.8,1.8,  2,2.2,1.8,0,  1.2,1.3,1.2,0,  5,4.8,5.2,0)
Performance <- data.frame(Industries,Districts,Sales)
Analysis <- aov(Sales ~ Industries + Districts + Industries*Districts)
summary(Analysis)
qf(1 - 0.05, 2, 36)
qf(1 - 0.05, 3, 36)
qf(1 - 0.05, 6, 36)





