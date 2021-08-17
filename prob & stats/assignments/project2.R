library(readr)
diet = read.csv("Diet.csv", row.names = 1)
diet$Weight.lost = diet$pre.weight - diet$weight6weeks  #creating additional column called weight.lost
diet$diet_type <- factor(diet$Diet, labels = c("A", "B", "C")) #creating additional column called diet_type to specify what diet they are using (1, 2 or 3)
diet$gender = factor(diet$gender, labels = c("Female", "Male")) #

####data cleaning (NA)
diet = na.omit(diet)

#for descriptive statistic info
print(summary(diet))

###Box plotting
##Age
boxplot(diet$Age, 
        main = "Age box plot",
        xlab = "Age",
        col = "blue",
        horizontal = TRUE
        )
##Height
boxplot(diet$Height,
        main = "Height box plot",
        xlab = "Height",
        col = "red",
        horizontal = TRUE
        )

##Weight
boxplot(diet$pre.weight,diet$weight6weeks,
        main ="Weight",
        at = c(1,2),
        names = c("preweight", "6weeks"),
        las = 2,
        col = c("orange","red"),
        border = "brown",
        horizontal =  TRUE
        )

##lost.weight
boxplot(diet$Weight.lost,
        main = "Lost weight",
        xlab = "Weight",
        col = "orange",
        horizontal = TRUE
        )

##anova2way
anova2 =  aov(diet$Weight.lost~diet$gender*diet$diet_type)
print(anova2)
result = anova2$residuals
hist(result, main = "Histogram of Residuals", xlab = "Residuals")
#alternative way to test normality using shapiro test
print(shapiro.test(result))

#Levene's Test for equality variances
library(car)
print(leveneTest(diet$Weight.lost~diet$gender*diet$diet_type))

#view ANOVA Table
print(summary(anova2))

#post-hoc test for finding the best diet
print(TukeyHSD(anova2))

