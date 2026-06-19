import { useState } from 'react'

const StatisticLine = ({ text, value }) => (
  <tr>
    <td>{text}</td>
    <td>{value}</td>
  </tr>
)

const Statistics = ({ good, neutral, bad }) => {
  const total = good + neutral + bad
  if (total === 0) {
    return <p>لم يتم جمع أي آراء بعد</p>
  }
  const average = (good - bad) / total
  const positivePercent = (good / total) * 100
  return (
    <table>
      <tbody>
        <StatisticLine text="جيد" value={good} />
        <StatisticLine text="عادي" value={neutral} />
        <StatisticLine text="سيء" value={bad} />
        <StatisticLine text="المجموع" value={total} />
        <StatisticLine text="المعدل" value={average.toFixed(2)} />
        <StatisticLine text="النسبة الإيجابية" value={`${positivePercent.toFixed(1)}%`} />
      </tbody>
    </table>
  )
}

const Button = ({ onClick, text }) => (
  <button onClick={onClick}>{text}</button>
)

const Unicafe = () => {
  const [good, setGood] = useState(0)
  const [neutral, setNeutral] = useState(0)
  const [bad, setBad] = useState(0)

  return (
    <div>
      <h1>أعطنا رأيك</h1>
      <Button onClick={() => setGood(good + 1)} text="جيد" />
      <Button onClick={() => setNeutral(neutral + 1)} text="عادي" />
      <Button onClick={() => setBad(bad + 1)} text="سيء" />
      <h2>الإحصائيات</h2>
      <Statistics good={good} neutral={neutral} bad={bad} />
    </div>
  )
}

export default Unicafe
