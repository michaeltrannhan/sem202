Industries <- gl(3,16,48, labels=c("Refrigeration","Construction Materials","Computer Services"))
Districts <- gl(4,4,48, labels=c("1","2","3","4"))
Sales <- c(2.5,2.7,2,3, 13.1,3.5,2.7,0, 2,2.4,0,0, 5,5.4,0,0, 0.6,10.4,0,0, 15,0,0,0, 9.5,9.3,9.1,0, 19.5,17.5,0,0, 1.2,1,9.8,1.8,  2,2.2,1.8,0,  1.2,1.3,1.2,0,  5,4.8,5.2,0)
Performance <- data.frame(Industries,Districts,Sales)
Analysis <- aov(Sales ~ Industries + Districts + Industries*Districts)
summary(Analysis)
qf(1 - 0.05, 2, 36)
qf(1 - 0.05, 3, 36)
qf(1 - 0.05, 6, 36)




