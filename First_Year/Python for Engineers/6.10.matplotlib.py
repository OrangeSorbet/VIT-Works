import matplotlib.pyplot as plt
import numpy as np

# Plot a line chart from given x and y data
def plot_line_chart(x, y):
    plt.figure(figsize=(10, 6))
    plt.plot(x, y, marker='o', color='b', label="Line Chart")  # Line plot with markers
    plt.title("Line Chart")  # Set chart title
    plt.xlabel("X-axis")     # Label for X-axis
    plt.ylabel("Y-axis")     # Label for Y-axis
    plt.legend()             # Display legend
    plt.grid(True)           # Enable grid
    plt.show()               # Show the plot

# Plot a bar chart from given x and y data
def plot_bar_chart(x, y):
    plt.figure(figsize=(10, 6))
    plt.bar(x, y, color='green', label="Bar Chart")  # Bar chart
    plt.title("Bar Chart")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.legend()
    plt.show()

# Plot a pie chart using x labels and y values
def plot_pie_chart(x, y):
    plt.figure(figsize=(7, 7))
    plt.pie(y, labels=x, autopct='%1.1f%%', startangle=140)  # Pie chart with labels and percentages
    plt.title("Pie Chart")
    plt.show()

# Plot a scatter chart from given x and y data
def plot_scatter_chart(x, y):
    plt.figure(figsize=(10, 6))
    plt.scatter(x, y, color='red', label="Scatter Chart")  # Scatter plot
    plt.title("Scatter Chart")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.legend()
    plt.show()

# Plot a histogram for both x and y data
def plot_histogram(x, y):
    plt.figure(figsize=(10, 6))
    plt.hist([x, y], bins=10, label=["X data", "Y data"], color=['blue', 'orange'])  # Histogram for x and y
    plt.title("Histogram")
    plt.xlabel("Values")
    plt.ylabel("Frequency")
    plt.legend()
    plt.show()

# Main function to handle user input and plotting
def main():
    # Ask user to input space-separated X and Y values
    print("To plot line chart, bar chart, pie chart, scatter chart, histogram for taking two different arrays as input")
    x = list(map(int, input("Enter the X values (space-separated): ").split()))
    y = list(map(int, input("Enter the Y values (space-separated): ").split()))

    # Validate if both lists are of equal length
    if len(x) != len(y):
        print("The X and Y arrays must have the same length.")
        return

    # Generate all required charts
    plot_line_chart(x, y)
    plot_bar_chart(x, y)
    plot_pie_chart(x, y)
    plot_scatter_chart(x, y)
    plot_histogram(x, y)

# Run the program
if __name__ == "__main__":
    main()
