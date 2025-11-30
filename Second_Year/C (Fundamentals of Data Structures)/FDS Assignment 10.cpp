#include <iostream>
#include <limits>
using namespace std;

struct AdjNode {
    int dest;
    int weight;
    AdjNode* next;
};

struct Vertex {
    int id;
    AdjNode* head;
};

class Graph {
private:
    Vertex* vertices;
    int maxVertices;
    int vertexCount;
    bool isDirected;

public:
    Graph(int size, bool directed) {
        maxVertices = size;
        vertexCount = 0;
        isDirected = directed;

        vertices = new Vertex[size];
        for (int i = 0; i < size; i++) {
            vertices[i].id = -1;
            vertices[i].head = nullptr;
        }
    }

    ~Graph() {
        for (int i = 0; i < vertexCount; i++) {
            AdjNode* curr = vertices[i].head;
            while (curr) {
                AdjNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] vertices;
    }

    void addVertex(int id) {
        if (vertexCount == maxVertices) {
            cout << "Vertex limit reached!\n";
            return;
        }

        if (findVertex(id) != -1) {
            cout << "Vertex already exists!\n";
            return;
        }

        vertices[vertexCount].id = id;
        vertices[vertexCount].head = nullptr;
        vertexCount++;

        cout << "Vertex " << id << " added.\n";
    }

    int findVertex(int id) {
        for (int i = 0; i < vertexCount; i++)
            if (vertices[i].id == id)
                return i;
        return -1;
    }

    void addEdge(int src, int dest, int weight) {
        if (src == dest) {
            cout << "Source and destination cannot be the same!\n";
            return;
        }

        int s = findVertex(src);
        int d = findVertex(dest);

        if (s == -1 || d == -1) {
            cout << "Invalid vertices!\n";
            return;
        }

        AdjNode* newNode = new AdjNode{dest, weight, vertices[s].head};
        vertices[s].head = newNode;

        if (!isDirected) {
            AdjNode* newNode2 = new AdjNode{src, weight, vertices[d].head};
            vertices[d].head = newNode2;
        }

        cout << "Edge " << src << " -> " << dest << " added.\n";
    }

    void deleteEdge(int src, int dest) {
        int s = findVertex(src);
        if (s == -1) {
            cout << "Source vertex not found!\n";
            return;
        }

        AdjNode* curr = vertices[s].head;
        AdjNode* prev = nullptr;

        while (curr) {
            if (curr->dest == dest) {
                if (prev) prev->next = curr->next;
                else vertices[s].head = curr->next;
                delete curr;
                cout << "Edge deleted.\n";

                if (!isDirected)
                    deleteEdge(dest, src);

                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Edge not found.\n";
    }

    void updateEdge(int src, int dest, int newWeight) {
        int s = findVertex(src);
        if (s == -1) {
            cout << "Source not found!\n";
            return;
        }

        AdjNode* curr = vertices[s].head;
        while (curr) {
            if (curr->dest == dest) {
                curr->weight = newWeight;
                cout << "Edge updated.\n";

                if (!isDirected)
                    updateEdge(dest, src, newWeight);

                return;
            }
            curr = curr->next;
        }

        cout << "Edge not found.\n";
    }

    void deleteVertex(int id) {
        int index = findVertex(id);
        if (index == -1) {
            cout << "Vertex not found!\n";
            return;
        }

        for (int i = 0; i < vertexCount; i++)
            deleteEdge(vertices[i].id, id);


        AdjNode* curr = vertices[index].head;
        while (curr) {
            AdjNode* temp = curr;
            curr = curr->next;
            delete temp;
        }

        for (int i = index; i < vertexCount - 1; i++)
            vertices[i] = vertices[i + 1];

        vertexCount--;
        cout << "Vertex deleted.\n";
    }

    void display() {
        cout << "\n--- Adjacency List ---\n";
        for (int i = 0; i < vertexCount; i++) {
            cout << vertices[i].id << " -> ";
            AdjNode* temp = vertices[i].head;
            while (temp) {
                cout << "(" << temp->dest << ", w=" << temp->weight << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void DFS(int start) {
        int s = findVertex(start);
        if (s == -1) {
            cout << "Start vertex not found!\n";
            return;
        }

        bool visited[100] = { false };
        int stack[100];
        int top = -1;

        stack[++top] = start;
        cout << "DFS: ";

        while (top != -1) {
            int v = stack[top--];

            int idx = findVertex(v);

            if (!visited[idx]) {
                cout << v << " ";
                visited[idx] = true;

                AdjNode* temp = vertices[idx].head;


                while (temp) {
                    int di = findVertex(temp->dest);
                    if (!visited[di])
                        stack[++top] = temp->dest;
                    temp = temp->next;
                }
            }
        }
        cout << endl;
    }

    void BFS(int start) {
        int s = findVertex(start);
        if (s == -1) {
            cout << "Start vertex not found!\n";
            return;
        }

        bool visited[100] = { false };
        int queue[100], front = 0, rear = 0;

        queue[rear++] = start;
        visited[s] = true;

        cout << "BFS: ";

        while (front != rear) {
            int v = queue[front++];
            cout << v << " ";

            int idx = findVertex(v);
            AdjNode* temp = vertices[idx].head;

            while (temp) {
                int di = findVertex(temp->dest);
                if (!visited[di]) {
                    visited[di] = true;
                    queue[rear++] = temp->dest;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int getPositiveInt() {
    int x;
    while (true) {
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter POSITIVE integer: ";
        }
        else if (x <= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Value must be > 0. Try again: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
    }
}

int main() {

    cout << "Directed Graph (1) or Undirected Graph (2)? ";
    int type = getPositiveInt();
    bool isDirected = (type == 1);

    cout << "Enter max number of vertices: ";
    int size = getPositiveInt();

    Graph g(size, isDirected);

    int choice, v1, v2, w;

    while (true) {
        cout << "\n===== GRAPH MENU =====\n";
        cout << "1. Add Vertex\n";
        cout << "2. Add Edge\n";
        cout << "3. Delete Edge\n";
        cout << "4. Update Edge\n";
        cout << "5. Delete Vertex\n";
        cout << "6. Display Graph\n";
        cout << "7. BFS\n";
        cout << "8. DFS\n";
        cout << "9. Exit\n";
        cout << "Choose: ";

        choice = getPositiveInt();

        switch (choice) {

        case 1:
            cout << "Enter vertex id: ";
            v1 = getPositiveInt();
            g.addVertex(v1);
            break;

        case 2:
            cout << "Enter src: ";
            v1 = getPositiveInt();
            cout << "Enter dest: ";
            v2 = getPositiveInt();
            cout << "Enter weight: ";
            w = getPositiveInt();
            g.addEdge(v1, v2, w);
            break;

        case 3:
            cout << "Enter src: ";
            v1 = getPositiveInt();
            cout << "Enter dest: ";
            v2 = getPositiveInt();
            g.deleteEdge(v1, v2);
            break;

        case 4:
            cout << "Enter src: ";
            v1 = getPositiveInt();
            cout << "Enter dest: ";
            v2 = getPositiveInt();
            cout << "Enter new weight: ";
            w = getPositiveInt();
            g.updateEdge(v1, v2, w);
            break;

        case 5:
            cout << "Enter vertex id: ";
            v1 = getPositiveInt();
            g.deleteVertex(v1);
            break;

        case 6:
            g.display();
            break;

        case 7:
            cout << "Start BFS from: ";
            v1 = getPositiveInt();
            g.BFS(v1);
            break;

        case 8:
            cout << "Start DFS from: ";
            v1 = getPositiveInt();
            g.DFS(v1);
            break;

        case 9:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
