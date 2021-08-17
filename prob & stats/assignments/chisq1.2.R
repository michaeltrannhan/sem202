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