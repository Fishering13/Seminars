from pathlib import Path
import sys,csv,statistics,json
root=Path(__file__).parent
sys.path.insert(0,str(root/'reports/deps'))
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
rows=list(csv.DictReader((root/'results/matrix_timings.csv').open()))
orders=['ijk','ikj','jik','jki','kij','kji']
sizes=sorted(set(int(r['n']) for r in rows))
med={(n,o):statistics.median(float(r['seconds']) for r in rows if int(r['n'])==n and r['order']==o) for n in sizes for o in orders}
with (root/'results/matrix_medians.csv').open('w',newline='') as f:
    w=csv.writer(f);w.writerow(['n']+orders)
    for n in sizes:w.writerow([n]+[med[n,o] for o in orders])
for label,ns in [('small',sizes[:5]),('medium',sizes[5:10]),('large',sizes[10:]),('all',sizes)]:
    fig,ax=plt.subplots(figsize=(8.2,4.6),layout='constrained')
    for o in orders:ax.plot(ns,[med[n,o] for n in ns],'-o',label=o,markersize=4)
    ax.set(xlabel='Размер квадратной матрицы n',ylabel='Время, с (медиана 5 запусков)',title='Умножение матриц — сравнение порядков циклов')
    ax.grid(alpha=.3);ax.legend(ncol=3);fig.savefig(root/'results'/('matrix_'+label+'.png'),dpi=180);plt.close(fig)
print(json.dumps({o:med[600,o] for o in orders}))
