## File was made by Claude AI Bot

import timeit

import pandas as pd
import plotly.express as px

from graph import create_an_N_test_graph, create_an_N_test_graph_smaller
from shortest_path import shortest_path_dijkstra, shortest_path_dijkstra_heap


def timed_row(n: int, mostly_connected: bool) -> dict:
    graph = create_an_N_test_graph(n) if mostly_connected else create_an_N_test_graph_smaller(n)

    dijkstra_time = timeit.timeit(
        lambda: shortest_path_dijkstra(graph, "0", str(n - 1)),
        number=1,
    )
    heap_time = timeit.timeit(
        lambda: shortest_path_dijkstra_heap(graph, "0", str(n - 1)),
        number=1,
    )

    return {
        "graph_type": "mostly_connected" if mostly_connected else "sparser",
        "N": n,
        "dijkstra": dijkstra_time,
        "dijkstra_heap": heap_time,
    }


def build_dataframe() -> pd.DataFrame:
    rows = []

    # Dense graphs grow quickly in runtime.
    for n in [50, 100, 200, 300, 400, 500]:
        rows.append(timed_row(n, mostly_connected=True))

    # Sparse graphs can handle much larger N.
    for n in [500, 1000, 2000, 4000, 6000, 8000, 10000]:
        rows.append(timed_row(n, mostly_connected=False))

    return pd.DataFrame(rows)


def main() -> None:
    df = build_dataframe()
    print(df.to_string(index=False))

    long_df = df.melt(
        id_vars=["graph_type", "N"],
        value_vars=["dijkstra", "dijkstra_heap"],
        var_name="algorithm",
        value_name="seconds",
    )

    fig = px.line(
        long_df,
        x="N",
        y="seconds",
        color="algorithm",
        symbol="graph_type",
        facet_col="graph_type",
        category_orders={"graph_type": ["mostly_connected", "sparser"]},
        markers=True,
        title="Dijkstra Timing Comparison",
    )
    fig.update_xaxes(matches=None)
    fig.update_xaxes(range=[0, 500], col=1)
    fig.update_yaxes(matches=None)
    fig.show()


if __name__ == "__main__":
    main()
