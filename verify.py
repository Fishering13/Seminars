from pathlib import Path
import subprocess
root=Path(__file__).resolve().parent
out=[]
for name in ['linear','binary','buckets']:
    for rate,expected in [('0',0),('0.5',500),('1',1000)]:
        text=subprocess.check_output([str(root/'build'/name),'--size','10000','--queries','1000','--seed','42','--hit-rate',rate],text=True)
        assert f'Найдено         : {expected} из 1000' in text
        out.append(f'{name}: hit-rate={rate}: found={expected}: OK')
    source=f'#define main supplied_main\n#include "{root}/SEMINARS/Seminar_5/{name}.cpp"\n#undef main\n#include <cassert>\nint main()\n{{\n'
    if name=='binary':
        source+='vector<uint64_t> a={1,1,9,UINT64_MAX};\nfor(uint64_t q: {0ULL,1ULL,2ULL,9ULL,18446744073709551615ULL}) assert(find_binary(a,q)==std::binary_search(a.begin(),a.end(),q));\nassert(!find_binary({},0));\n'
    elif name=='linear':
        source+='assert(!find_linear({},0)); assert(find_linear({0,5,5,UINT64_MAX},UINT64_MAX)); assert(!find_linear({1},2));\n'
    else:
        source+='Buckets b;build_buckets({0,256,UINT64_MAX},b);assert(find_in_buckets(b,0));assert(find_in_buckets(b,256));assert(find_in_buckets(b,UINT64_MAX));assert(!find_in_buckets(b,512));build_buckets({},b);assert(!find_in_buckets(b,0));\n'
    source+='return 0;\n}\n'
    p=root/'build'/('test_'+name+'.cpp');p.write_text(source)
    subprocess.run(['g++','-std=c++17','-O2',str(p),'-o',str(p.with_suffix(''))],check=True)
    subprocess.run([str(p.with_suffix(''))],check=True)
    out.append(name+': empty, boundary and repeated values: OK')
subprocess.run([str(root/'build/matrix_benchmark'),'--quick'],cwd=root/'build',check=True,stdout=subprocess.DEVNULL)
out.append('matrix: n=1,2,3,10; all six orders match: OK')
test=root/'build/test_matrix.cpp'
test.write_text('#define main benchmark_main\n#include "'+str(root/'SEMINARS/Seminar_6/matrix_benchmark.cpp')+'"\n#undef main\n#include <cassert>\nint main()\n{\nMatrix b={1,2,3,4},c={5,6,7,8},expected={20,23,44,51};\nfor(Kernel f: {multiply_ijk,multiply_ikj,multiply_jik,multiply_jki,multiply_kij,multiply_kji})\n{\nMatrix a(4,1);f(a,b,c,2);assert(a==expected);\n}\n}\n')
subprocess.run(['g++','-std=c++17','-O2',str(test),'-o',str(test.with_suffix(''))],check=True)
subprocess.run([str(test.with_suffix(''))],check=True)
out.append('matrix: independent known 2x2 product with nonzero initial A: OK')
(root/'results/verification.txt').write_text('\n'.join(out)+'\n')
print('\n'.join(out))
