import sys
import os
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QVBoxLayout, QHBoxLayout, QPushButton, QLineEdit, QListWidget
from PyQt5.QtCore import Qt

class ToDoListGUI(QWidget):
    def __init__(self):
        super().__init__()
        self.welcome_label = QLabel("Python To-Do GUI", self)
        self.input_line = QLineEdit(self)
        self.input_line.setPlaceholderText("Enter New Task...")
        self.task_list = QListWidget(self)
        self.add_button = QPushButton("Add Task", self)
        self.remove_button = QPushButton("Remove Task", self)
        self.initUI()
        self.loadTasksList()

    def initUI(self):
        self.setWindowTitle("Python To-Do-List GUI")
        self.setGeometry(300, 300, 400, 300)
        
        layout = QVBoxLayout()
        layout.addWidget(self.welcome_label)
        layout.addWidget(self.input_line)
        layout.addWidget(self.task_list)

        button_layout = QHBoxLayout()
        button_layout.addWidget(self.add_button)
        button_layout.addWidget(self.remove_button)
        layout.addLayout(button_layout)
        self.setLayout(layout)

        self.welcome_label.setAlignment(Qt.AlignCenter)
        self.input_line.setAlignment(Qt.AlignCenter)

#This is a little bit of CSS for the styling of the programs display.

        self.setStyleSheet("""
            QWidget{
                background-color: #f2f2f2;
            }
            QLabel {
                font-family: Helvetica;
                font-size: 25px;      
                color: #333;         
            }
            QLineEdit {
                border: 2px solid #aaa;
                border-radius: 5px;
                padding: 5px;
                font-size: 16px;
            }
            QListWidget {
                border: 2px solid #aaa;
                border-radius: 5px;
                font-size: 16px;
                padding: 5px;
            }
            QPushButton {
                background-color: #5cb85c;
                color: white;
                border: none;
                border-radius: 5px;
                padding: 10px;
                font-size: 16px;
            }
            QPushButton:hover {
                background-color: #4cae4c;
            }
            QPushButton:pressed {
                background-color: #449d44;
            }
        """)

        self.add_button.clicked.connect(self.addTasks)
        self.remove_button.clicked.connect(self.removeTask)
        self.input_line.returnPressed.connect(self.addTasks)

#This function is complete, after program is complete check for better ways to write this and then delete this comment.
    def addTasks(self):
        task = self.input_line.text().strip()
        if task:
            self.task_list.addItem(task)
            self.input_line.clear()

#This function is complete, after program is complete check for better ways to write this and then delete this comment.
    def removeTask(self):
        selected_task = self.task_list.selectedItems()
        if not selected_task:
            return
        for item in selected_task:
            self.task_list.takeItem(self.task_list.row(item))

#This is the function responsible for saving the list of tasks to a seperate text file.
    def saveTasksList(self):
        with open("ToDoTasks.txt", "w", encoding="utf-8") as file:
            for index in range(self.task_list.count()):
                task = self.task_list.item(index).text()
                file.write(task + "\n")

#This function is responsible for displaying the saved tasks.
    def loadTasksList(self):
        if os.path.exists("ToDoTasks.txt"):
            with open("ToDoTasks.txt", "r", encoding="utf-8") as file:
                for line in file:
                    task = line.strip()
                    if task:
                        self.task_list.addItem(task)

#This function is responsible for saving the tasks once we click the exit button.
    def closeEvent(self, event):
        self.saveTasksList()
        event.accept()

#This is the main function that is used to create and maintain a window displaying my GUI.
if __name__ == '__main__':
    app = QApplication(sys.argv)
    toDoList_app = ToDoListGUI()
    toDoList_app.show()
    sys.exit(app.exec_())
