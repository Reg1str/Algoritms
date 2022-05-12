#include <fstream>
#include <vector>

using namespace std;

//ТОПОЛОГИЧЕСКАЯ СОРТИРОВКА ДЛЯ ГРАФА
void dfs(int &cur, vector<vector<int>> &graph, vector<bool> &passed, vector<int> &tsorted) {
    passed[cur] = true;
    for (auto i: graph[cur])
        if (!passed[i])
            dfs(i, graph, passed, tsorted);
    tsorted.push_back(cur);
}

//ТОПОЛОГИЧЕСКАЯ СОРТИРОВКА ДЛЯ ТРАНСПОНИРОВАННОГО ГРАФА
void tdfs(int &cur, vector<vector<int>> &t_graph, vector<bool> &passed, vector<int> &components) {
    passed[cur] = true;
    components.push_back(cur);
    for (auto i: t_graph[cur])
        if (!passed[i])
            tdfs(i,t_graph,passed,components);
}

int main() {

    ifstream fin("cond.in");
    ofstream fout("cond.out");

    vector <vector<int>> graph(100000);
    vector <vector<int>> t_graph(100000);
    vector<bool> passed;
    vector<int> tsorted;
    vector<int> components;
    vector<int> answer;

    int n, m, x, y;
    fin >> n >> m;
    graph.resize(n);
    t_graph.resize(n);
    answer.assign(n, 0);

    //ЗАПОЛНЯЕМ СПИСКИ СМЕЖНОСТИ ДЛЯ ГРАФА
    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        graph[x - 1].push_back(y - 1);
        t_graph[y - 1].push_back(x - 1);
    }

    //ТОПОЛОГИЧЕСКИ СОРТИРУЕМ ОБЫЧНЫЙ ГРАФ
    passed.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!passed[i])
            dfs(i,graph, passed, tsorted);
    passed.assign(n, false);

    //ПОДСЧЕТ СИЛЬНЫХ КОМПОНЕНТ СВЯЗНОСТЕЙ
    int component_number = 0;
    for (int i = passed.size() - 1; i >= 0; i--)
    {
        if (!passed[tsorted[i]]) {
            components.clear();
            tdfs(tsorted[i], t_graph, passed, components);
            component_number++;
            for (int j: components)
                answer[j] = component_number;
        }
    }

    fout << component_number << endl;
    for (int vertexes: answer)
        fout << vertexes << " ";
    return 0;
}