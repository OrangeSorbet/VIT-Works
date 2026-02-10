args <- commandArgs(trailingOnly = TRUE)
n <- as.integer(args[1])
nums <- as.numeric(args[2:(n + 1)])

get_mode <- function(x) {
  u <- unique(x)
  u[which.max(tabulate(match(x, u)))]
}

cat("Numbers:", nums, "\n")
cat("Mean   :", mean(nums), "\n")
cat("Median :", median(nums), "\n")
cat("Mode   :", get_mode(nums), "\n")

# Rscript mean_median_mode.R 6 89 56 34 32 78 78
# (total numbers) (numbers...)