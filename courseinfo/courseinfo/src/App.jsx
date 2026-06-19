import Header from './components/Header'
import Content from './components/Content'
import Total from './components/Total'
import StudentCard from './components/StudentCard'

const App = () => {
  const course = 'تطبيقات تطوير Half Stack'
  const part1 = 'أساسيات React'
  const exercises1 = 10
  const part2 = 'استخدام props لتمرير البيانات'
  const exercises2 = 7
  const part3 = 'حالة المكوّن'
  const exercises3 = 14

  return (
    <div>
      <Header course={course} />
      <Content
        part1={part1} exercises1={exercises1}
        part2={part2} exercises2={exercises2}
        part3={part3} exercises3={exercises3}
      />
      <Total
        exercises1={exercises1}
        exercises2={exercises2}
        exercises3={exercises3}
      />

      <hr />

      <h2>بطاقات الطلاب</h2>
      <StudentCard name="أحمد العمري"   major="علوم الحاسب"      gpa={3.8} />
      <StudentCard name="سارة الزهراني" major="هندسة البرمجيات"  gpa={3.2} />
      <StudentCard name="محمد القحطاني" major="الذكاء الاصطناعي" gpa={3.6} />
    </div>
  )
}

export default App
