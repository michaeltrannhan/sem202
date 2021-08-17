##generating data
numCase <- c(11, 5, 5,
             15 ,3 ,7,
             3, 22, 3,
             41, 30, 15
             )
countries <- rep(c("US","Japan","UK"),4)
typeOfCancer <- c(rep("Colorectal",3),rep("Breast",3),rep("Stomach",3),rep("Other",3))
DeathRate <- data.frame(typeOfCancer, countries, numCase)


##displaying result
result = aov(numCase~typeOfCancer+countries, data = DeathRate)
anova(result)


