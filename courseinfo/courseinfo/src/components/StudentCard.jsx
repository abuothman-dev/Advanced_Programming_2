// تمرين وظيفة إضافي — بطاقة طالب
// المطلوب: مكوّن StudentCard يعرض معلومات طالب + 3 بطاقات مختلفة

function StudentCard({ name, major, gpa, imageUrl }) {
  return (
    <div className="card">
      <img src={imageUrl} alt={name} />
      <h2>{name}</h2>
      <p>التخصص: {major}</p>
      <p>المعدل: {gpa}</p>
      <span className={gpa >= 3.5 ? "badge-success" : "badge-warning"}>
        {gpa >= 3.5 ? "متفوق" : "جيد"}
      </span>
    </div>
  )
}

StudentCard.defaultProps = {
  imageUrl: "/default-avatar.png",
  gpa: 0
}

export default StudentCard
