import Additems from "./AddItems";
import Heading from "./Heading";
import Todoitem1 from "./TodoItem1";
import Todoitem2 from "./Todoitem2";

function App(){
  return <center id='todo-container'>

    <Heading/>
    <div class="container text-center">
        <Additems/>
        <Todoitem1/>
        <Todoitem2/>
        </div>

    </center>
   
}
export default App;