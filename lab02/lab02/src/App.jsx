import Counter from './components/Counter'
import Unicafe from './components/Unicafe'
import Anecdotes from './components/Anecdotes'
import Todos from './components/Todos'

const App = () => {
  return (
    <div>
      <Counter />
      <hr />
      <Unicafe />
      <hr />
      <Anecdotes />
      <hr />
      <Todos />
    </div>
  )
}

export default App
